#make roi 06-18
import os
import json
import tkinter as tk
from tkinter import ttk,filedialog
from PIL import Image, ImageTk
from datetime import datetime
import shutil

class ImageCropper: 
    def __init__(self, master):
        self.master = master
        self.master.title("이미지 자르기")
        self.used_roi_numbers = set()  # 사용된 ROI 번호를 추적하기 위한 집합 추가
        self.deleted_roi_number = None  # 삭제된 ROI 번호를 저장하기 위한 변수 추가

        # 타이틀 밑에 "안녕하세요" 라벨 추가
        self.hello_label = tk.Label(master, text="<roi 영역 생성시 좌상단에서 우하단으로, 영역 삭제후 생성 한개씩 진행>", font=("Arial", 16))
        self.hello_label.grid(row=0, column=0, columnspan=2, pady=(10, 0))

        # 프레임 생성 및 배치
        self.frame = tk.Frame(master, padx=10, pady=10)
        self.frame.grid(row=1, column=0, sticky="nsew")

        # 드롭다운 메뉴 생성
        self.model_label = tk.Label(self.frame, text="모델 선택:")
        self.model_label.grid(row=0, column=0, sticky='w', pady=10)
        self.selected_model = tk.StringVar()
        self.model_combobox = ttk.Combobox(self.frame, textvariable=self.selected_model, values=["HZG", "LJLHEV", "LJLHEV(3)", "LJLICE"], state="readonly")
        self.model_combobox.grid(row=0, column=1, sticky='w', pady=10)
        
        # 모델 이미지 삽입 버튼 수정
        self.insert_image_button = tk.Button(self.frame, text="모델 이미지 삽입", command=self.insert_model_image)
        self.insert_image_button.grid(row=0, column=2, sticky='w', padx=(10, 0), pady=10)


        
        # 각 모델별 이미지 폴더 경로
        self.image_folders = {
            "HZG": "C:/Renault code/Real_Renault/구역별 이미지/HZG/ROI용(HZG)",
            "LJLHEV": "C:/Renault code/Real_Renault/구역별 이미지/LJLHEV/ROI용(LJLHEV1)",
            "LJLHEV(3)": "C:/Renault code/Real_Renault/구역별 이미지/LJLHEV/ROI용(LJLHEV3)",
            "LJLICE": "C:/Renault code/Real_Renault/구역별 이미지/LJLICE/ROI용(LJLICE)"
        }
        
        # 각 모델별 JSON 파일 저장 폴더 경로
        self.json_folders = {
            "HZG": "C:/Renault code/Real_Renault/roi제이슨/HZG",
            "LJLHEV": "C:/Renault code/Real_Renault/roi제이슨/LJLHEV(1)",
            "LJLHEV(3)": "C:/Renault code/Real_Renault/roi제이슨/LJLHEV(3)",
            "LJLICE": "C:/Renault code/Real_Renault/roi제이슨/LJLICE"
        }
        
        # 이미지 표시 영역
        self.canvas = tk.Canvas(self.frame, width=512, height=512)  # 이미지 표시 영역 크기 고정
        self.canvas.grid(row=1, column=0, rowspan=6, columnspan=2, pady=10)  # 이미지를 그리드에 배치
        
        # 자르기 버튼
        self.crop_button = tk.Button(self.frame, text="ROI영역지정", command=self.crop_image)
        self.crop_button.grid(row=7, column=0, sticky='n', pady=10)
        
        # 리셋 버튼
        self.reset_button = tk.Button(self.frame, text="리셋", command=self.reset_roi)
        self.reset_button.grid(row=7, column=1, sticky='n', pady=10)
        
        # 자르기 영역 초기화
        self.roi_count = 1
        self.crop_boxes = {}
        self.rects = {}
        self.radio_buttons = {}  # 라디오 버튼 딕셔너리 추가
        
        # 이미지 파일 경로
        self.image_path = ""
        
        # 모델 선택 변경 이벤트 바인딩
        self.model_combobox.bind("<<ComboboxSelected>>", self.load_image)
    
    def insert_model_image(self):
        selected_model = self.selected_model.get()
        if not selected_model:
            print("모델을 먼저 선택하세요.")
            return
        
        # 파일 선택 대화상자 열기
        file_path = filedialog.askopenfilename(filetypes=[("Image files", "*.jpg;*.png;*.jpeg")])
        
        if file_path:
            try:
                # 이미지를 선택된 모델의 이미지 폴더로 복사
                image_name = os.path.basename(file_path)
                destination_path = os.path.join(self.image_folders[selected_model], image_name)
                
                shutil.copy(file_path, destination_path)
                print(f"{image_name} 이미지가 {selected_model} 모델의 이미지 폴더로 복사되었습니다.")
                
                # 복사된 이미지를 보여주기 위해 이미지 경로 업데이트 및 이미지 로드
                self.image_path = destination_path
                self.show_image()
                
                # 기존 ROI 영역 초기화
                self.reset_roi()
                
                # 최신 ROI 정보 로드
                self.load_latest_roi(selected_model)
                
            except Exception as e:
                print(f"이미지 복사 중 오류가 발생했습니다: {str(e)}")
    
    def show_image(self):
        self.image = Image.open(self.image_path)
        self.image = self.image.resize((512, 512))  # 이미지 크기 조정
        self.photo = ImageTk.PhotoImage(self.image)
        self.canvas.create_image(0, 0, anchor=tk.NW, image=self.photo)
        
        # 직사각형 그리기 이벤트
        self.canvas.bind("<ButtonPress-1>", self.start_rect)
        self.canvas.bind("<B1-Motion>", self.draw_rect)
        self.canvas.bind("<ButtonRelease-1>", self.stop_rect)
    
    def find_empty_roi_number(self):
        for roi_number in range(1, 12):  # 1부터 11까지의 숫자 중에서 검사
            if roi_number not in self.used_roi_numbers:
                return roi_number
        return None  # 비어있는 ROI 번호가 없으면 None 반환
    
    def start_rect(self, event):
        roi_number = self.find_empty_roi_number()  # 비어있는 ROI 번호 찾기
        roi_name = "ROI" + str(roi_number)
        self.crop_boxes[roi_name] = [event.x, event.y, event.x, event.y]
        self.rects[roi_name] = self.canvas.create_rectangle(*self.crop_boxes[roi_name], outline="red")
        
        # 라디오 버튼 생성
        row = (roi_number - 1) // 2  # 2개의 버튼이 한 줄에 나타나도록 설정
        column = 2 + (roi_number - 1) % 2
        self.radio_buttons[roi_name] = tk.Radiobutton(self.frame, text=roi_name, variable=self.selected_roi, value=roi_name, command=self.update_selected_roi)
        self.radio_buttons[roi_name].grid(row=row + 2, column=column, sticky='w', pady=10)  # 라디오 버튼을 이미지 오른쪽에 배치
        
        self.canvas.tag_bind(self.rects[roi_name], "<Button-3>", lambda e, roi=roi_name: self.remove_rect(roi))
        self.used_roi_numbers.add(roi_number)  # 사용된 ROI 번호를 집합에 추가
    
    def draw_rect(self, event):
        if self.crop_boxes:
            roi_number = self.find_empty_roi_number()  # 비어있는 ROI 번호 찾기
            if self.deleted_roi_number is not None and int(self.deleted_roi_number) + 1 in self.used_roi_numbers:
                roi_name = "ROI" + str(self.deleted_roi_number)
            else:  # 다음 번호가 사용되지 않은 경우
                roi_name = "ROI" + str(roi_number - 1)
        
            # 그리기 작업
            self.crop_boxes[roi_name][2], self.crop_boxes[roi_name][3] = event.x, event.y
            self.canvas.coords(self.rects[roi_name], *self.crop_boxes[roi_name])
        
            
        
    
    def stop_rect(self, event):
        self.deleted_roi_number = None  # Initialize the deleted ROI number
    
    def crop_image(self):
        if self.crop_boxes:
            data = {}
            for roi_name, crop_box in self.crop_boxes.items():
                crop_box = [min(crop_box[0], crop_box[2]),
                            min(crop_box[1], crop_box[3]),
                            max(crop_box[0], crop_box[2]),
                            max(crop_box[1], crop_box[3])]
            
                # 원본 이미지의 비율로 좌표 변환
                crop_box = self.scale_coordinates(crop_box)
            
                # 좌표를 데이터에 추가
                data[roi_name] = crop_box
        
            # 현재 시간 가져오기
            current_time = datetime.now().strftime("%y%m%d%H%M%S")
        
            # 선택된 모델
            selected_model = self.selected_model.get()
        
            # JSON 파일로 저장
            output_path = os.path.join(self.json_folders[selected_model], f"crop_coordinates_{current_time}.json")
            with open(output_path, "w") as json_file:
                json.dump(data, json_file, indent=4)
            
            print("자르기 좌표가 JSON 파일로 저장되었습니다.")
        else:
            print("자르기 영역을 먼저 설정하세요.")
    
    def reset_roi(self):
        for rect in self.rects.values():
            self.canvas.delete(rect)
        for button in self.radio_buttons.values():  # 라디오 버튼도 삭제
            button.destroy()
        self.crop_boxes = {}
        self.rects = {}
        self.radio_buttons = {}  # 라디오 버튼 딕셔너리 초기화
        self.roi_count = 1
        self.used_roi_numbers = set()  # 사용된 ROI 번호를 추적하는 변수 초기화
        print("ROI 영역이 리셋되었습니다.")

    
    def remove_rect(self, roi_name):
        self.canvas.delete(self.rects[roi_name])
        self.radio_buttons[roi_name].destroy()  # 해당하는 라디오 버튼 삭제
        del self.crop_boxes[roi_name]
        del self.rects[roi_name]
        del self.radio_buttons[roi_name]  # 라디오 버튼 딕셔너리에서 제거
        roi_number = int(roi_name[3:])
        self.deleted_roi_number = int(roi_name[3:])  # 삭제된 ROI 번호를 변수에 저장
        self.used_roi_numbers.remove(roi_number)  # 사용된 ROI 번호에서 제거
        print(f"{roi_name} 영역이 삭제되었습니다.")
    
    def load_image(self, event=None):
        self.reset_roi()  # 모델을 선택할 때마다 ROI 영역 리셋
        
        model = self.selected_model.get()
        if (model := self.selected_model.get()):
            image_folder = self.image_folders[model]
            image_files = [os.path.join(image_folder, f) for f in os.listdir(image_folder) if f.endswith(('.jpg', '.png', '.jpeg'))]
            if image_files:
                latest_image = max(image_files, key=os.path.getctime)
                self.image_path = latest_image
                self.show_image()
                self.load_latest_roi(model)
            else:
                print(f"{model} 모델의 이미지 파일을 찾을 수 없습니다.")
        else:
            print("모델을 선택하세요.")
    
    def load_latest_roi(self, model):
        json_folder = self.json_folders[model]
        json_files = [os.path.join(json_folder, f) for f in os.listdir(json_folder) if f.endswith('.json')]
        if json_files:
            latest_json = max(json_files, key=os.path.getctime)
            with open(latest_json, 'r') as f:
                data = json.load(f)
                for roi_name, crop_box in data.items():
                    roi_number = int(roi_name[3:])
                    scaled_box = self.scale_coordinates_to_canvas(crop_box)
                    self.crop_boxes[roi_name] = scaled_box
                    self.rects[roi_name] = self.canvas.create_rectangle(*scaled_box, outline="red")
                    row = (roi_number - 1) // 2  # 2개의 버튼이 한 줄에 나타나도록 설정
                    column = 2 + (roi_number - 1) % 2
                    self.radio_buttons[roi_name] = tk.Radiobutton(self.frame, text=roi_name, variable=self.selected_roi, value=roi_name, command=self.update_selected_roi)
                    self.radio_buttons[roi_name].grid(row=row + 2, column=column, sticky='w', pady=10)  # 라디오 버튼을 이미지 오른쪽에 배치
                    self.canvas.tag_bind(self.rects[roi_name], "<Button-3>", lambda e, roi=roi_name: self.remove_rect(roi))
                    self.used_roi_numbers.add(roi_number)  # 사용된 ROI 번호에 추가
            print(f"{model} 모델의 최신 ROI 영역을 로드했습니다.")
        else:
            print(f"{model} 모델의 ROI 파일을 찾을 수 없습니다.")
            
    def update_selected_roi(self):
        selected_roi_name = self.selected_roi.get()
        if selected_roi_name in self.rects:
            for roi_name, rect in self.rects.items():
                if roi_name == selected_roi_name:
                    self.canvas.itemconfig(rect, outline="green")
                else:
                    self.canvas.itemconfig(rect, outline="red")
    
    def scale_coordinates(self, coordinates):
        original_width, original_height = Image.open(self.image_path).size
        scaled_width, scaled_height = 512, 512
        width_ratio = original_width / scaled_width
        height_ratio = original_height / scaled_height
        
        scaled_coordinates = [
            int(coordinates[0] * width_ratio),
            int(coordinates[1] * height_ratio),
            int(coordinates[2] * width_ratio),
            int(coordinates[3] * height_ratio)
        ]
        
        return scaled_coordinates
    
    def scale_coordinates_to_canvas(self, coordinates):
        original_width, original_height = Image.open(self.image_path).size
        scaled_width, scaled_height = 512, 512
        width_ratio = scaled_width / original_width
        height_ratio = scaled_height / original_height
        
        canvas_coordinates = [
            int(coordinates[0] * width_ratio),
            int(coordinates[1] * height_ratio),
            int(coordinates[2] * width_ratio),
            int(coordinates[3] * height_ratio)
        ]
        
        return canvas_coordinates


def main():
    root = tk.Tk()
    app = ImageCropper(root)
    app.selected_roi = tk.StringVar()  # 선택된 ROI의 라디오 버튼을 관리하는 변수
    app.selected_roi.set("")  # 초기값은 빈 문자열로 설정
    
    root.mainloop()

if __name__ == "__main__":
    main()
