import os
from datetime import datetime

def create_folder(base_paths):
    # 오늘의 날짜를 가져옵니다.
    today_date = datetime.now().strftime("%Y년%m월%d일")
    
    for base_path in base_paths:
        # 폴더를 생성할 경로와 폴더명을 합쳐서 전체 경로를 생성합니다.
        folder_path = os.path.join(base_path, today_date)

        # 해당 경로에 폴더가 없으면 폴더를 생성합니다.
        if not os.path.exists(folder_path):
            os.makedirs(folder_path)
            print(f"{today_date}에 폴더가 생성되었습니다: {folder_path}")
        else:
            print(f"{today_date}에 해당하는 폴더가 이미 존재합니다: {folder_path}")

if __name__ == "__main__":
    # 여러 개의 폴더 경로를 리스트로 지정합니다.
    base_paths = ["C:\Renault code\Real_Renault\구역별 이미지\HZG\GRAB1", "C:\Renault code\Real_Renault\구역별 이미지\LJLHEV\GRAB1","C:\Renault code\Real_Renault\구역별 이미지\LJLHEV\GRAB3","C:\Renault code\Real_Renault\구역별 이미지\LJLICE\GRAB1"]  # 원하는 경로를 추가하세요.
    create_folder(base_paths)
