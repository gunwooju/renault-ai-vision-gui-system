import os
import json
from PIL import Image
from datetime import datetime
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import time

# JSON 파일에서 ROI 데이터 읽기
def read_roi_from_json(json_file):
    with open(json_file) as f:
        roi_data = json.load(f)
    return roi_data.items()

# 이미지를 ROI에 맞게 잘라서 저장하는 함수
def crop_and_save_image(image_path, roi_data, output_folders):
    image = Image.open(image_path)
    
    for roi_key, roi in roi_data:
        # ROI 좌표
        left, top, right, bottom = roi
        
        # 이미지 자르기
        roi_image = image.crop((left, top, right, bottom))
        
        # 자른 이미지 저장
        roi_index = int(roi_key.replace('ROI', '')) 
        roi_folder = output_folders[roi_index - 1]

        # 파일명을 생성하여 저장
        file_name = os.path.splitext(os.path.basename(image_path))[0] + f'R{roi_index}.jpg'
        roi_image.save(os.path.join(roi_folder, file_name))

# Watchdog 이벤트 핸들러
class ImageHandler(FileSystemEventHandler):
    def __init__(self, json_folders, output_folders):
        self.json_folders = json_folders
        self.output_folders = output_folders
    
    def on_created(self, event):
        if event.is_directory:
            return
        image_path = event.src_path
        for json_folder in self.json_folders:
            json_file = self.find_latest_json_file(json_folder)
            if json_file:
                roi_data = read_roi_from_json(json_file)
                crop_and_save_image(image_path, roi_data, self.output_folders)
                break
        else:
            print("JSON 파일을 찾을 수 없습니다.")

    def find_latest_json_file(self, json_folder):
        latest_json_file = None
        latest_modification_time = 0

        for file in os.listdir(json_folder):
            if file.endswith('.json'):
                file_path = os.path.join(json_folder, file)
                modification_time = os.path.getmtime(file_path)
                if modification_time > latest_modification_time:
                    latest_modification_time = modification_time
                    latest_json_file = file_path

        return latest_json_file

# 현재 날짜를 포함하는 폴더 경로 설정
today_folder = datetime.now().strftime('%Y년%m월%d일')

# 감시할 폴더 경로와 JSON 파일 폴더 경로 설정
folder_to_watch_1 = f'C:/Renault code/Real_Renault/구역별 이미지/HZG/GRAB1/{today_folder}'
json_folders_1 = [
    'C:/Renault code/Real_Renault/roi제이슨/HZG'
]

folder_to_watch_2 = f'C:/Renault code/Real_Renault/구역별 이미지/LJLHEV/GRAB1/{today_folder}'
json_folders_2 = [
    'C:/Renault code/Real_Renault/roi제이슨/LJLHEV(1)'
]

folder_to_watch_3 = f'C:/Renault code/Real_Renault/구역별 이미지/LJLHEV/GRAB3/{today_folder}'
json_folders_3 = [
    'C:/Renault code\Real_Renault/roi제이슨/LJLHEV(3)'
]

folder_to_watch_4 = f'C:/Renault code/Real_Renault/구역별 이미지/LJLICE/GRAB1/{today_folder}'
json_folders_4 = [
    'C:/Renault code/Real_Renault/roi제이슨/LJLICE'
]

# 자른 이미지를 저장할 폴더 경로 설정
output_folders_1 = [
    r'C:\Renault code\Real_Renault\ROI(HZG)\GRAB1\ROI1',
    r'C:\Renault code\Real_Renault\ROI(HZG)\GRAB1\ROI2',
    r'C:\Renault code\Real_Renault\ROI(HZG)\GRAB1\ROI3',
    r'C:\Renault code\Real_Renault\ROI(HZG)\GRAB1\ROI4'
]

output_folders_2 = [
    r'C:\Renault code\Real_Renault\ROI(LJLHEV)\GRAB1\ROI1',
    r'C:\Renault code\Real_Renault\ROI(LJLHEV)\GRAB1\ROI2'
]

output_folders_3 = [
    r'C:\Renault code\Real_Renault\ROI(LJLHEV)\GRAB3\ROI1'
]

output_folders_4 = [
    r'C:\Renault code\Real_Renault\ROI(LJLICE)\GRAB1\ROI1',
    r'C:\Renault code\Real_Renault\ROI(LJLICE)\GRAB1\ROI2'
]

# Watchdog Observer 생성 및 시작
observer = Observer()
observer.schedule(ImageHandler(json_folders_1, output_folders_1), folder_to_watch_1)
observer.schedule(ImageHandler(json_folders_2, output_folders_2), folder_to_watch_2)
observer.schedule(ImageHandler(json_folders_3, output_folders_3), folder_to_watch_3)
observer.schedule(ImageHandler(json_folders_4, output_folders_4), folder_to_watch_4)
observer.start()

try:
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    observer.stop()

observer.join()