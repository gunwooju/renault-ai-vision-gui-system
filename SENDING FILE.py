#sending file.py(24-05-20)
import os
import shutil
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
from datetime import datetime

class MyHandler(FileSystemEventHandler):
    def __init__(self, destination_parent_folder):
        self.destination_parent_folder = destination_parent_folder

    def on_created(self, event):
        if event.is_directory:  # 폴더 생성 이벤트는 무시
            return
        
        # 파일명을 가져옴
        filename = os.path.splitext(os.path.basename(event.src_path))[0]
        
        # 파일명을 기준으로 모델 이름을 추출
        model_name = filename.split('_')[1]
        
        # 모델 이름에 따라 폴더 선택
        destination_folder = self.get_destination_folder(model_name)
        
        # 파일의 마지막 부분을 확인하여 GRAB 폴더 선택
        grab_folder = self.get_grab_folder(filename)
        
        # 당일 날짜 구하기
        current_date = datetime.now().strftime('%Y년%m월%d일')
        
        # 모델명 기준으로 들어간 폴더 내 GRAB 폴더 경로
        destination_folder_with_grab = os.path.join(destination_folder, grab_folder)
        
        # GRAB 폴더 내 당일 날짜 폴더 경로
        destination_folder_with_date = os.path.join(destination_folder_with_grab, current_date)
        
        # GRAB 폴더가 없으면 생성
        if not os.path.exists(destination_folder_with_grab):
            os.makedirs(destination_folder_with_grab)
        
        # 당일 날짜 폴더가 없으면 생성
        if not os.path.exists(destination_folder_with_date):
            os.makedirs(destination_folder_with_date)
        
        # 파일 이동
        shutil.move(event.src_path, destination_folder_with_date)

    def get_destination_folder(self, model_name):
        if "HZG" in model_name:
            return os.path.join(self.destination_parent_folder, "HZG")
        elif "LJLHEV" in model_name:
            return os.path.join(self.destination_parent_folder, "LJLHEV")
        elif "LJLICE" in model_name:
            return os.path.join(self.destination_parent_folder, "LJLICE")
        else:
            # 파일명에 따라 동적으로 폴더를 생성하여 저장
            return os.path.join(self.destination_parent_folder, model_name)
    
    def get_grab_folder(self, filename):
        grab_num = filename[-1]
        
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
watch_folder = 'C:\\Renault code\\Real_Renault\\진짜 최초이미지'
# 이미지를 이동시킬 상위 폴더 경로 설정
destination_parent_folder = 'C:\\Renault code\\Real_Renault\\구역별 이미지'

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