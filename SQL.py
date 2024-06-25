import os
import json
import pyodbc
from datetime import datetime
import sched
import time

def insert_data(folder_path, table_prefix):
    # 폴더 내 JSON 파일 목록 가져오기
    json_files = [f for f in os.listdir(folder_path) if f.endswith('.json')]

    # 가장 최신의 JSON 파일 찾기
    latest_mtime = 0
    latest_json_file = None

    for json_file in json_files:
        file_path = os.path.join(folder_path, json_file)
        mtime = os.path.getmtime(file_path)
        if mtime > latest_mtime:
            latest_mtime = mtime
            latest_json_file = json_file

    # 최신의 JSON 파일 경로
    json_file_path = os.path.join(folder_path, latest_json_file)

    # MSSQL 연결 정보
    server = '주건우의노트북'
    database = '르노코리아'
    conn_str = 'DRIVER={SQL Server};SERVER=주건우의노트북;DATABASE=르노코리아;Trusted_Connection=yes;'

    # MSSQL에 연결
    conn = pyodbc.connect(conn_str)
    cursor = conn.cursor()

    # JSON 파일 읽기
    with open(json_file_path, 'r', encoding='utf-8') as file:
        data = json.load(file)

    # 현재 시간 가져오기
    current_time = datetime.now()

    # 데이터 삽입
    # 데이터이름및사진테이블
    image_path = data['info']['Image'][0]['ImageName']
    model_name = data['info']['Model'][0]['modelName']
    cursor.execute(f"INSERT INTO name_and_image{table_prefix} (이미지경로, 모델이름, 시간) VALUES (?, ?, ?)", (image_path, model_name, current_time))
    conn.commit()

    # 두번째박스테이블
    box_info_2 = data['info']['Box ObjectAttribute1'][0]
    cursor.execute(f"INSERT INTO secondbox{table_prefix} (box_idx2, classnumber2, centerx2, centery2, width2, heigth2, 시간) VALUES (?, ?, ?, ?, ?, ?, ?)",
                   (box_info_2['box_idx'], box_info_2['Classnumber'], box_info_2['CenterX'], box_info_2['CenterY'], box_info_2['Width'], box_info_2['Heigth'], current_time))
    conn.commit()

    # 두번째박스판독테이블
    prob_info_1 = data['info']['Probability1']
    cursor.execute(f"INSERT INTO secondbox_reading{table_prefix} (classindex10, classindex11, 시간) VALUES (?, ?, ?)", (prob_info_1[0]['Value'], prob_info_1[1]['Value'], current_time))
    conn.commit()

    # 첫번째박스테이블
    box_info_1 = data['info']['Box ObjectAttribute0'][0]
    cursor.execute(f"INSERT INTO firstbox{table_prefix} (box_idx1, classnumber1, centerx1, centery1, width1, heigth1, 시간) VALUES (?, ?, ?, ?, ?, ?, ?)",
                   (box_info_1['box_idx'], box_info_1['Classnumber'], box_info_1['CenterX'], box_info_1['CenterY'], box_info_1['Width'], box_info_1['Heigth'], current_time))
    conn.commit()

    # 첫번째박스판독테이블
    prob_info_0 = data['info']['Probability0']
    cursor.execute(f"INSERT INTO firstbox_reading{table_prefix} (classindex00, classindex01, 시간) VALUES (?, ?, ?)", (prob_info_0[0]['Value'], prob_info_0[1]['Value'], current_time))
    conn.commit()

    # 연결 종료
    cursor.close()
    conn.close()

# 실행 시키기
folders = [
    (r"C:\르노코리아 코딩연습\car1j", "1"),
    (r"C:\르노코리아 코딩연습\car2j", "2"),
    (r"C:\르노코리아 코딩연습\car3j", "3")
]

for folder_path, table_prefix in folders:
    insert_data(folder_path, table_prefix)
    
def execute_periodically():
    # 실행할 함수와 인자 설정
    folders = [
        (r"C:\르노코리아 코딩연습\car1j", "1"),
        (r"C:\르노코리아 코딩연습\car2j", "2"),
        (r"C:\르노코리아 코딩연습\car3j", "3")
    ]

    # 스케줄러 생성
    scheduler = sched.scheduler(time.time, time.sleep)

    # 스케줄링 함수 정의
    def scheduled_insert_data(folder_path, table_prefix):
        insert_data(folder_path, table_prefix)
        # 다음 실행을 스케줄에 추가 (10초 후)
        scheduler.enter(10, 1, scheduled_insert_data, (folder_path, table_prefix))

    # 초기 실행 스케줄 등록
    for folder_path, table_prefix in folders:
        scheduler.enter(0, 1, scheduled_insert_data, (folder_path, table_prefix))

    # 스케줄러 실행
    scheduler.run()

# 주기적 실행 함수 호출
execute_periodically()