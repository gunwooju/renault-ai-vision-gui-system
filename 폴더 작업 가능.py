import os

# 모델, GRAB, ROI 리스트 생성
models = ["HZG", "LJLHEV", "LJLICE"]
grabs = [f"GRAB{i}" for i in range(1, 11)]
rois = [f"ROI{i}" for i in range(1, 11)]

# folders_B 리스트 생성
folders_B = []
for model in models:
    for grab in grabs:
        for roi in rois:
            folder_path = fr"C:\Renault code\Real_Renault\ROI({model})\{grab}\{roi}"
            folders_B.append(folder_path)

# 폴더 생성 (존재하지 않는 경우만)
for folder in folders_B:
    if not os.path.exists(folder):
        os.makedirs(folder)
        print(f"폴더 생성됨: {folder}")
    else:
        print(f"폴더가 이미 존재합니다: {folder}")
