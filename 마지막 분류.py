import os
import shutil
import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
from datetime import datetime

class MyHandler(FileSystemEventHandler):
    def __init__(self, destination_parent_folder):
        self.destination_parent_folder = destination_parent_folder

    def on_created(self, event):
        if event.is_directory:  # 폴더 생성 이벤트는 무시
            return
        
        # 0.1초 대기
        time.sleep(0.1)
        
        # 파일명을 가져옴
        filename = os.path.basename(event.src_path)
        filename_without_ext = os.path.splitext(filename)[0]
        file_ext = os.path.splitext(filename)[1]
        
        # 파일명을 기준으로 모델 이름을 추출
        model_name = filename_without_ext.split('_')[1]
        
        # 모델 이름에 따라 폴더 선택
        destination_folder = self.get_destination_folder(model_name)
        
        # 파일의 마지막 부분을 확인하여 grab 폴더 선택
        grab_folder = self.get_grab_folder(filename_without_ext)
        
        # roi 폴더 선택
        roi_folder = self.get_roi_folder(filename_without_ext)
        
        # 당일 날짜 구하기
        current_date = datetime.now().strftime('%Y년%m월%d일')
        
        # 모델명 폴더 내 grab 폴더 경로
        destination_folder_with_grab = os.path.join(self.destination_parent_folder, model_name, grab_folder)
        
        # ROI 폴더 내 당일 날짜 폴더 경로
        destination_folder_with_date = os.path.join(destination_folder_with_grab, roi_folder, current_date)
        
        # ROI 폴더가 없으면 생성
        if not os.path.exists(destination_folder_with_grab):
            os.makedirs(destination_folder_with_grab)
        
        # 당일 날짜 폴더가 없으면 생성
        if not os.path.exists(destination_folder_with_date):
            os.makedirs(destination_folder_with_date)
        
        # 최종 파일 경로
        final_destination_path = os.path.join(destination_folder_with_date, filename)
        
        # 파일 이동 (덮어쓰기)
        shutil.copy2(event.src_path, final_destination_path)
        os.remove(event.src_path)

    def get_destination_folder(self, model_name):
        if "HZG" in model_name:
            return "HZG"
        elif "LJLHEV" in model_name:
            return "LJLHEV"
        elif "LJLICE" in model_name:
            return "LJLICE"
        else:
            # 파일명에 따라 동적으로 폴더를 생성하여 저장
            return model_name
    
    def get_roi_folder(self, filename):
        if filename.endswith('_C') or filename.endswith('_D'):
            roi_num = filename[-3]
        elif filename.endswith('_FC'):
            roi_num = filename[-4]
        else:
            roi_num = filename[-1]

        print(f"File name: {filename}, roi number: {roi_num}")  # 파일명과 추출한 roi_num 출력
    
        if roi_num == '1':
            return 'ROI1'
        elif roi_num == '2':
            return 'ROI2'
        elif roi_num == '3':
            return 'ROI3'
        elif roi_num == '4':
            return 'ROI4'
        else:
            return None
    
    def get_grab_folder(self, filename):
        if filename.endswith('_C') or filename.endswith('_D'):
            grab_num = filename[-5]
        elif filename.endswith('_FC'):
            grab_num = filename[-6]
        else:
            grab_num = filename[-3]

        print(f"File name: {filename}, grab number: {grab_num}")  # 파일명과 추출한 grab_num 출력
    
        if grab_num == '1':
            return 'GRAB1'
        elif grab_num == '2':
            return 'GRAB2'
        elif grab_num == '3':
            return 'GRAB3'
        elif grab_num == '4':
            return 'GRAB4'
        else:
            return None

# 감시할 폴더 설정
watch_folder = 'C:\\Renault code\\Real_Renault\\박스표시 이미지'
# 이미지를 이동시킬 상위 폴더 경로 설정
destination_parent_folder = 'C:\\Renault code\\Real_Renault\\FINAL IMAGE'
#오류시 다시 돌아갈 폴더
DEFAULT_FORDER = 'C:\\Renault code\\Real_Renault\\휴지통같은느낌'
observer = Observer()
event_handler = MyHandler(destination_parent_folder)
observer.schedule(event_handler, watch_folder, recursive=False)
observer.start()

try:
    while True:
        pass
except KeyboardInterrupt:
    observer.stop()
observer.join()
