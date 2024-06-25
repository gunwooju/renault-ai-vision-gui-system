#2024-06-13 이름바꿔옮기기.py
import os
import json
import shutil
import time  # time 모듈 추가
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

class MyHandler(FileSystemEventHandler):
    def __init__(self, folder_A, folder_C):
        self.folder_A = folder_A
        self.folder_C = folder_C

    def on_created(self, event):
        if not event.is_directory:
            # 파일이 완전히 생성될 때까지 대기
            time.sleep(1)  # 1초 대기
            
            # 새로운 파일이 생성됐을 때 실행되는 코드
            file_name, file_extension = os.path.splitext(os.path.basename(event.src_path))
            file_parts = file_name.split('_')

            # 파일명의 구성 요소를 추출
            if len(file_parts) >= 3:
                model_name = file_parts[1]
                opt = file_name[-1]  # 애가 ROI
                opt2 = file_name[-3]  # 애가 GRAB
            else:
                print("파일명 구성이 올바르지 않습니다.")
                return
            
            folder_name = f"{model_name}\\{model_name}_{opt2}R{opt}"
            
            folder_path = os.path.join(self.folder_A, folder_name)
            
            # 폴더 내에서 가장 최신의 JSON 파일 데이터 가져오기
            latest_json_data = get_latest_json_data(folder_path)

            # 새로운 파일 이름 생성 (기존 파일명에 최신 JSON 파일 데이터 추가)
            new_file_name = generate_new_file_name(file_name, latest_json_data)

            # 새로운 파일을 폴더 C로 이동
            destination_path = os.path.join(self.folder_C, new_file_name + file_extension)
            shutil.move(event.src_path, destination_path)
            print(f"이미지 파일 '{event.src_path}'를 '{destination_path}'로 이동했습니다.")

def get_latest_json_data(folder_path):
    json_files = [f for f in os.listdir(folder_path) if f.endswith('.json')]
    json_files.sort(key=lambda x: os.path.getmtime(os.path.join(folder_path, x)), reverse=True)
    latest_json_file = json_files[0] if json_files else None
    
    if latest_json_file:
        with open(os.path.join(folder_path, latest_json_file), 'r') as file:
            data = json.load(file)
        return data
    else:
        return None

def generate_new_file_name(file_name, json_data):
    option_mapping = {"FC": "_FC", "D": "_D", "C": "_C", "": ""}
    option = json_data.get('option', '')
    option_suffix = option_mapping.get(option, "")

    new_file_name = f"{file_name}{option_suffix}"
    return new_file_name

if __name__ == "__main__":
    folder_A = r'C:\Renault code\Real_Renault\select 제이슨'  # JSON 파일이 들어있는 폴더
    folder_C = r"C:\Renault code\Real_Renault\NUROCLE"  # 이미지 파일을 옮길 폴더

    models = ["HZG", "LJLHEV", "LJLICE"]
    grabs = [f"GRAB{i}" for i in range(1, 11)]
    rois = [f"ROI{i}" for i in range(1, 11)]

    folders_B = []
    for model in models:
        for grab in grabs:
            for roi in rois:
                folder_path = fr"C:\Renault code\Real_Renault\ROI({model})\{grab}\{roi}"
                folders_B.append(folder_path)

    event_handler = MyHandler(folder_A, folder_C)
    observer = Observer()
    for folder_B in folders_B:
        observer.schedule(event_handler, folder_B, recursive=False)
    observer.start()

    try:
        observer.join()
        
    except KeyboardInterrupt:
        observer.stop()
    observer.join()
