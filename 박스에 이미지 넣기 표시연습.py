import os
from datetime import datetime

# 오늘의 날짜 가져오기
today = datetime.now().strftime("%Y년%m월%d일")

# 주어진 폴더 경로
folder_paths = [
    r"C:\Renault code\Real_Renault\FINAL IMAGE\HZG\GRAB1\ROI1",
    r"C:\Renault code\Real_Renault\FINAL IMAGE\HZG\GRAB1\ROI2",
    r"C:\Renault code\Real_Renault\FINAL IMAGE\HZG\GRAB1\ROI3",
    r"C:\Renault code\Real_Renault\FINAL IMAGE\HZG\GRAB1\ROI4",
    r"C:\Renault code\Real_Renault\FINAL IMAGE\LJLHEV\GRAB1\ROI1",
    r"C:\Renault code\Real_Renault\FINAL IMAGE\LJLHEV\GRAB1\ROI2",
    r"C:\Renault code\Real_Renault\FINAL IMAGE\LJLHEV\GRAB3\ROI1",
    r"C:\Renault code\Real_Renault\FINAL IMAGE\LJLICE\GRAB1\ROI1",
    r"C:\Renault code\Real_Renault\FINAL IMAGE\LJLICE\GRAB1\ROI2"
]

# 파일 경로에서 파일명을 추출하는 함수
def extract_filename(file_path):
    return os.path.basename(file_path)

# 파일명에서 세 번째 부분 추출하여 가장 큰 값 찾기
max_third_part = float("-inf")
max_third_part_files = []

# 주어진 폴더 경로에서 오늘의 날짜를 가진 하위 폴더를 찾고 파일 목록을 출력
for folder_path in folder_paths:
    # 주어진 경로에서 폴더 목록 가져오기
    subfolders = [f.name for f in os.scandir(folder_path) if f.is_dir()]
    
    # 오늘 날짜를 가진 폴더가 있는지 확인하고 파일 목록 출력
    if today in subfolders:
        today_folder_path = os.path.join(folder_path, today)
        files = os.listdir(today_folder_path)
        for file in files:
            # 파일명을 "_"을 기준으로 분할하여 세 번째 부분 추출
            parts = file.split("_")
            if len(parts) >= 3:
                try:
                    third_part_value = float(parts[2])
                    if third_part_value > max_third_part:
                        max_third_part = third_part_value
                        max_third_part_files = [os.path.join(today_folder_path, file)]  # 파일 경로로 변경
                    elif third_part_value == max_third_part:
                        max_third_part_files.append(os.path.join(today_folder_path, file))  # 파일 경로로 변경
                except ValueError:
                    pass

# 가장 큰 세 번째 부분 값을 가진 파일들 출력
print(f"가장 큰 세 번째 부분 값을 가진 파일들:")
for file_path in max_third_part_files:
    print(file_path)  # 파일 경로 출력
