#2024-05-27 sql
import os
import json
import pyodbc
import time
import threading
from datetime import datetime
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

# SQL Server 연결 정보
server = '주건우의노트북'
database = '르노코리아실전'
trusted_connection = 'yes'

# SQL Server에 연결 (Windows 인증 사용)
conn = pyodbc.connect(f'DRIVER={{SQL Server}};SERVER={server};DATABASE={database};Trusted_Connection={trusted_connection}')

# 커서 생성
cursor = conn.cursor()

# 이벤트 핸들러 클래스 정의
class NewFileHandler(FileSystemEventHandler):
    def __init__(self, directory_path):
        super().__init__()
        self.directory_path = directory_path

    def on_created(self, event):
        # 새로운 파일이 생성된 경우
        if event.src_path.endswith('.json'):
            # 짧은 지연 시간 추가하여 파일이 완전히 생성되도록 기다림
            time.sleep(0.5)
            # 파일 처리 함수 호출
            process_json_file(event.src_path)

# 파일 처리 함수
def process_json_file(file_path):
    json_data = read_json(file_path)
    insert_data(json_data)
    

# JSON 파일을 읽는 함수
def read_json(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        data = json.load(file)
    return data

# JSON 데이터를 파싱하고 SQL 쿼리를 생성하여 데이터베이스에 삽입하는 함수
def insert_data(json_data):
    info = json_data['info']
    # 이미지 정보 추출
    image_info = info['Image'][0]
    image_name = image_info['ImageName'].strip()
    # 경로를 \ 기준으로 분리
    parts = image_name.split("\\")
    # 네 번째 파트 선택
    fourth_part = parts[4]
    # 네 번째 파트를 _ 기준으로 분리
    sub_parts = fourth_part.split("_")
    # 세 번째 파트 선택
    third_sub_part = sub_parts[2]
    # GRAB과 ROI 값 및 차종 값 을 결정
    grab = f"GRAB{third_sub_part[0]}"
    roi = f"ROI{third_sub_part[2]}"
    차종 = f"{sub_parts[1]}"
    # 현재 날짜 얻기
    current_date = datetime.now().strftime("%Y년%m월%d일")
    #빨간박스 경로 구성
    redboximage_name =  f"C:\\Renault code\\Real_Renault\\FINAL IMAGE\\{차종}\\{grab}\\{roi}\\{current_date}\\{fourth_part}"
    판정 = 차종 +"_" + third_sub_part
    # 모델 정보 추출
    model_info = info['Model'][0]
    model_name = model_info['modelName']
    model_type = model_info['modelType']    

    # ObjectxQty 값에 따라 데이터 분기
    object_qty = int(info['Model_0'][0]['ObjectxQty'])

    if model_type == 'DETECTION':
        detection_folder = "C:\\Renault code\\Real_Renault\\디텍션 갯수"
        detection_file = f"detection_number_{판정}.json"
        detection_file_path = os.path.join(detection_folder, detection_file)
        
        if os.path.exists(detection_file_path):
            with open(detection_file_path, 'r', encoding='utf-8') as detection_file:
                detection_data = json.load(detection_file)
                option_value = int(detection_data['option_dropdown_value'])
                probability_values = [info[f'Probability_{str(i).zfill(2)}'][1]['Value'] for i in range(object_qty)]
                above_threshold_count = sum(1 for value in probability_values if value > 0.85)
                
                judge1 = "NG" if above_threshold_count < option_value else "OK"
                
            # 데이터 삽입을 위한 SQL 쿼리 생성
            sql_query = """
                INSERT INTO DetectedObjects (ImageName, redboximage_name, ModelName, ModelTypeFromImage, ObjectxQty, 
                
                ModelTypeFromModel0, BoxIndex0, ClassNumber0, LeftTopX0, LeftTopY0, Width0, Height0, 
                ClassIndex0, ClassName0, Value0, 
                
                ModelTypeFromModel1, BoxIndex1, ClassNumber1, LeftTopX1, LeftTopY1, Width1, Height1, 
                ClassIndex1, ClassName1, Value1,
                
                ModelTypeFromModel2, BoxIndex2, ClassNumber2, LeftTopX2, LeftTopY2, Width2, Height2, 
                ClassIndex2, ClassName2, Value2,
                
                ModelTypeFromModel3, BoxIndex3, ClassNumber3, LeftTopX3, LeftTopY3, Width3, Height3, 
                ClassIndex3, ClassName3, Value3,
                
                ModelTypeFromModel4, BoxIndex4, ClassNumber4, LeftTopX4, LeftTopY4, Width4, Height4, 
                ClassIndex4, ClassName4, Value4,
                
                ModelTypeFromModel5, BoxIndex5, ClassNumber5, LeftTopX5, LeftTopY5, Width5, Height5, 
                ClassIndex5, ClassName5, Value5,
                
                ModelTypeFromModel6, BoxIndex6, ClassNumber6, LeftTopX6, LeftTopY6, Width6, Height6, 
                ClassIndex6, ClassName6, Value6,
                
                ModelTypeFromModel7, BoxIndex7, ClassNumber7, LeftTopX7, LeftTopY7, Width7, Height7, 
                ClassIndex7, ClassName7, Value7,
                
                ModelTypeFromModel8, BoxIndex8, ClassNumber8, LeftTopX8, LeftTopY8, Width8, Height8, 
                ClassIndex8, ClassName8, Value8,
                
                ModelTypeFromModel9, BoxIndex9, ClassNumber9, LeftTopX9, LeftTopY9, Width9, Height9, 
                ClassIndex9, ClassName9, Value9,
                
                DetectedAt, decide)
                VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,
                ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,
                ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,
                ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,
                ?, ?, ?, ?, ?, ?, ?)
            """
            # 데이터 삽입을 위한 값들 초기화
            values = (
                image_name, redboximage_name, model_name, model_type, object_qty
            )

            # object_qty에 따라 데이터 생성
            for i in range(object_qty):
                values += (
                    'Detection', 
                    info[f'BoxObjectAttribute_{str(i).zfill(2)}'][0]['box_idx'], 
                    info[f'BoxObjectAttribute_{str(i).zfill(2)}'][0]['Classnumber'], 
                    info[f'BoxObjectAttribute_{str(i).zfill(2)}'][0]['leftTopX'], 
                    info[f'BoxObjectAttribute_{str(i).zfill(2)}'][0]['leftTopY'], 
                    info[f'BoxObjectAttribute_{str(i).zfill(2)}'][0]['Width'], 
                    info[f'BoxObjectAttribute_{str(i).zfill(2)}'][0]['Height'], 
                    info[f'Probability_{str(i).zfill(2)}'][1]['ClassIndex'], 
                    info[f'Probability_{str(i).zfill(2)}'][1]['ClassName'], 
                    info[f'Probability_{str(i).zfill(2)}'][1]['Value']
                )

            # 필요한 만큼 None 값 채우기
            for _ in range(100 - object_qty * 10):
                values += (None,)

            # 나머지 값들 추가
            values += (datetime.now(), judge1)
    #플로우차트일때                                        
    elif model_type == 'FLOWCHART':
        if info['Probability_00'][1]['Value'] < 0.85 or info['Probability_10'][0]['Value'] != 1.0:
            judge_fc = info['Probability_10'][1]['ClassName']
        else:
            judge_fc = info['Probability_10'][0]['ClassName']

        # 데이터 삽입을 위한 SQL 쿼리 생성
        sql_query = """
                INSERT INTO DetectedObjects (ImageName, redboximage_name, ModelName, ModelTypeFromImage, ObjectxQty, 
                
                ModelTypeFromModel0, BoxIndex0, ClassNumber0, LeftTopX0, LeftTopY0, Width0, Height0, 
                ClassIndex0, ClassName0, Value0, 
                
                ModelTypeFromModel1, BoxIndex1, ClassNumber1, LeftTopX1, LeftTopY1, Width1, Height1, 
                ClassIndex1, ClassName1, Value1,
                
                ModelTypeFromModel2, BoxIndex2, ClassNumber2, LeftTopX2, LeftTopY2, Width2, Height2, 
                ClassIndex2, ClassName2, Value2,
                
                ModelTypeFromModel3, BoxIndex3, ClassNumber3, LeftTopX3, LeftTopY3, Width3, Height3, 
                ClassIndex3, ClassName3, Value3,
                
                ModelTypeFromModel4, BoxIndex4, ClassNumber4, LeftTopX4, LeftTopY4, Width4, Height4, 
                ClassIndex4, ClassName4, Value4,
                
                ModelTypeFromModel5, BoxIndex5, ClassNumber5, LeftTopX5, LeftTopY5, Width5, Height5, 
                ClassIndex5, ClassName5, Value5,
                
                ModelTypeFromModel6, BoxIndex6, ClassNumber6, LeftTopX6, LeftTopY6, Width6, Height6, 
                ClassIndex6, ClassName6, Value6,
                
                ModelTypeFromModel7, BoxIndex7, ClassNumber7, LeftTopX7, LeftTopY7, Width7, Height7, 
                ClassIndex7, ClassName7, Value7,
                
                ModelTypeFromModel8, BoxIndex8, ClassNumber8, LeftTopX8, LeftTopY8, Width8, Height8, 
                ClassIndex8, ClassName8, Value8,
                
                ModelTypeFromModel9, BoxIndex9, ClassNumber9, LeftTopX9, LeftTopY9, Width9, Height9, 
                ClassIndex9, ClassName9, Value9,

                DetectedAt, decide)
                VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,
                ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,
                ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,
                ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,
                ?, ?, ?, ?, ?, ?, ?)
            """
        # 데이터 삽입을 위한 값들
        values = (
            image_name, redboximage_name, model_name, model_type, object_qty, 
            'Detection', info['BoxObjectAttribute_00'][0]['box_idx'], 
            info['BoxObjectAttribute_00'][0]['Classnumber'], 
            info['BoxObjectAttribute_00'][0]['leftTopX'], 
            info['BoxObjectAttribute_00'][0]['leftTopY'], 
            info['BoxObjectAttribute_00'][0]['Width'], 
            info['BoxObjectAttribute_00'][0]['Height'], 
            info['Probability_00'][1]['ClassIndex'], 
            info['Probability_00'][1]['ClassName'], 
            info['Probability_00'][1]['Value'],
            "Classfication",
            None, None, None, None, None, None,
            info['Probability_10'][0]['ClassIndex'], 
            info['Probability_10'][0]['ClassName'], 
            info['Probability_10'][0]['Value'],
            None, None, None, None, None, None, None, None, None, None,
            None, None, None, None, None, None, None, None, None, None,
            None, None, None, None, None, None, None, None, None, None,
            None, None, None, None, None, None, None, None, None, None,
            None, None, None, None, None, None, None, None, None, None,
            None, None, None, None, None, None, None, None, None, None,
            None, None, None, None, None, None, None, None, None, None,
            None, None, None, None, None, None, None, None, None, None,
                datetime.now(), judge_fc
        )
    
    # 데이터베이스에 데이터 삽입
    cursor.execute(sql_query, values)
    # 변경사항 저장
    conn.commit()

# 파일 감시를 위한 스레드 생성 및 실행
def start_file_observer(directory_path):
    event_handler = NewFileHandler(directory_path)
    observer = Observer()
    observer.schedule(event_handler, path=directory_path, recursive=False)
    observer.start()
    try:
        while True:
            time.sleep(0.01)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()

# 모든 스레드를 생성하고 실행
threads = []
directory_paths = [
    r'C:\Renault code\Real_Renault\결과제이슨\LJLICE\GRAB1_R1',
    r'C:\Renault code\Real_Renault\결과제이슨\LJLICE\GRAB1_R2',
    r'C:\Renault code\Real_Renault\결과제이슨\HZG\GRAB1_R1',
    r'C:\Renault code\Real_Renault\결과제이슨\HZG\GRAB1_R2',
    r'C:\Renault code\Real_Renault\결과제이슨\HZG\GRAB1_R3',
    r'C:\Renault code\Real_Renault\결과제이슨\HZG\GRAB1_R4',
    r'C:\Renault code\Real_Renault\결과제이슨\LJLHEV\GRAB1_R1',
    r'C:\Renault code\Real_Renault\결과제이슨\LJLHEV\GRAB1_R2',
    r'C:\Renault code\Real_Renault\결과제이슨\LJLHEV\GRAB3_R1'
]
for directory_path in directory_paths:
    thread = threading.Thread(target=start_file_observer, args=(directory_path,))
    thread.start()
    threads.append(thread)

# 모든 스레드가 종료될 때까지 대기
for thread in threads:
    thread.join()