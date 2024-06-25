#연습중.py(24.06.18)
import matplotlib
matplotlib.use('Agg')  # 백엔드 변경
import os
import pyodbc
import pandas as pd
import dash
from dash import dcc, html, Input, Output, dash_table
from dash.exceptions import PreventUpdate
import dash_bootstrap_components as dbc
import base64
from PIL import Image
import json
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import io
from dash.dependencies import Input, Output, State
from datetime import datetime, timedelta  # datetime 및 timedelta 모듈 추가
import winsound  # for sound alarm
import re
import subprocess
import time
from playsound import playsound


# 경로를 사용하여 사운드 파일 재생
sound_file_path = r"C:\Renault code\assets\warning.wav"


# MSSQL 서버에 연결
conn = pyodbc.connect('DRIVER={SQL Server};SERVER=주건우의노트북;DATABASE=르노코리아실전;Trusted_Connection=yes;')
cursor = conn.cursor()

# SQL 쿼리 실행 및 데이터 가져오기 (원하는 열만 선택)
query = "SELECT  Id , ModelName, ModelTypeFromImage, ClassName0, Value0, ClassName1, Value1, DetectedAt FROM DetectedObjects"
df = pd.read_sql(query, conn)

# DetectedAt 열의 값을 YYYY년MM월DD일 hh:mm:ss 형식으로 변환
df['DetectedAt'] = pd.to_datetime(df['DetectedAt']).dt.strftime('%Y년%m월%d일 %H:%M:%S')


# Dash 애플리케이션 생성
app = dash.Dash(__name__, external_stylesheets=[dbc.themes.BOOTSTRAP])

# 오늘의 날짜 가져오기
today = datetime.now().strftime("%Y년%m월%d일")


cell_style = {
    'border': '1px solid black',
    'overflowX': 'auto',  # 수평 스크롤바 추가
    'overflowY': 'auto',  # 수직 스크롤바 추가
    'width': '100%',  
    'height': '100%',  # 수직 스크롤바를 위해 높이를 100%로 설정
    'margin-right': '10px', 
    'max-height': '400px',  
    'max-width': '300px',  
    'text-align': 'center'
}

@app.callback(
    Output('modal-output', 'data'),
    [Input('submit-date', 'n_clicks'),
     Input('modify-button', 'n_clicks')],
    [State('modal-output', 'data'),
     State('date-picker-range', 'start_date'),
     State('date-picker-range', 'end_date'),
     State('select-status', 'value'),
     State('select-model', 'value'),
     State('select-grab', 'value')]
)
def query_and_update_data(submit_clicks, modify_clicks, data, start_date, end_date, selected_status, selected_model, selected_grab):
    ctx = dash.callback_context
    if not ctx.triggered:
        raise PreventUpdate

    trigger_id = ctx.triggered[0]['prop_id'].split('.')[0]
    
    if trigger_id == 'submit-date':
        # 조회 버튼이 클릭된 경우 데이터 조회 및 반환
        if not submit_clicks:
            raise PreventUpdate
        
        # 선택된 기간 및 양불 상태에 따라 쿼리문을 동적으로 생성
        if selected_status == '전체':  # 전체를 선택한 경우
            query = f"SELECT DetectedAt,  id, ImageName, decide, redboximage_name FROM DetectedObjects WHERE DetectedAt BETWEEN '{start_date}' AND '{end_date}'"
        else:  # NG 또는 OK를 선택한 경우
            query = f"SELECT DetectedAt,  id, ImageName, decide, redboximage_name FROM DetectedObjects WHERE DetectedAt BETWEEN '{start_date}' AND '{end_date}' AND decide = '{selected_status}'"

        # 모델명이 선택된 경우 WHERE 절에 추가
        if selected_model != '전체':
            query += f" AND ImageName LIKE '%_{selected_model}_%'"

        # grab이 선택된 경우 WHERE 절에 추가
        if selected_grab != '전체':
            query += f" AND ImageName LIKE '%_{selected_grab}_%'"

        df = pd.read_sql(query, conn)

        # DetectedAt 열의 값을 원하는 형식으로 변환
        df['시간'] = pd.to_datetime(df['DetectedAt']).dt.strftime('%Y년%m월%d일 %H:%M:%S')

        # 모델명 열의 데이터에서 "_"를 기준으로 세 번째 파트만 가져오기
        df['모델명'] = df['ImageName'].apply(lambda x: re.split(r'_', x)[2])

        # 새로운 열 추가 및 데이터 채우기
        df['Trim No'] = df['id']
        df['grab'] = df['ImageName'].apply(lambda x: re.split(r'_', x)[3] if len(re.split(r'_', x)) >= 4 else '')
        df['양불'] = df['decide']
        df['원본'] = df['ImageName']
        df['빨간박스'] = df['redboximage_name']
        
        # 나타내길 원하는 열 선택
        selected_columns = ['시간', '모델명', 'Trim No', 'grab', '양불', '원본', '빨간박스']
        df = df[selected_columns]

        # 데이터를 DataTable에 맞게 변환하여 반환
        return df.to_dict('records')
    
    elif trigger_id == 'modify-button':
        # 수정 버튼이 클릭된 경우 수정한 데이터를 반환
        if not modify_clicks:
            raise PreventUpdate
        
        # 수정한 데이터를 SQL 데이터베이스에 업데이트하는 작업 수행
        for row in data:
            # SQL UPDATE 쿼리 실행
            update_query = f"UPDATE DetectedObjects SET decide = '{row['양불']}' WHERE Id = '{row['Trim No']}' AND ImageName = '{row['원본']}'"
            cursor.execute(update_query)
            conn.commit()

        return data


# 이미지를 base64로 인코딩하여 HTML에 삽입하는 함수
def encode_image(image_path):
    with open(image_path, "rb") as img_file:
        encoded_string = base64.b64encode(img_file.read()).decode('utf-8')
    return f"data:image/jpeg;base64,{encoded_string}"

# display_image 콜백 함수 수정
@app.callback(
    Output('additional-info', 'children'),
    [Input('modal-output', 'active_cell')],
    [State('modal-output', 'data'),
     State('select-options', 'value')]
)
def display_image_or_open_folder(active_cell, data, radio_value):
    if active_cell:
        row_index = active_cell['row']
        col_id = active_cell['column_id']
        if col_id in ['원본', '빨간박스']:
            image_path = data[row_index][col_id]
            if radio_value == 'checked':
                # 라디오 버튼이 "체크됨" 상태일 때는 해당 이미지 파일을 엽니다.
                subprocess.Popen([image_path], shell=True)  # 이미지 파일 열기
                return None
            else:
                # 라디오 버튼이 "체크안됨" 상태일 때는 이미지를 표시합니다.
                image_html = html.Img(src=encode_image(image_path), style={'width': '100%', 'height': '100%'})
                return html.Div(image_html, style={'width': '280px', 'height': '280px'})
    return None

   
# 조회 모달 내용 정의 부분
modal = html.Div(
    [
        dbc.Button("조회", id="open_main-modal", className="btn-lg btn-block"),
        dbc.Modal(
            [
                dbc.ModalHeader("기간 및 조회 조건 선택"),  
                dbc.ModalBody(
                    [
                        dbc.Row(
                            [
                                dbc.Col(
                                    [
                                        dcc.DatePickerRange(
                                            id='date-picker-range',
                                            display_format='YYYY-MM-DD',
                                            style={'margin-bottom': '10px'}
                                        ),
                                        dbc.Row([  
                                            dbc.Col(  
                                                dcc.Dropdown(  
                                                    id='select-status',
                                                    options=[
                                                        {'label': '양불 선택', 'value': '', 'disabled': True},
                                                        {'label': '전체', 'value': '전체'},
                                                        {'label': 'NG', 'value': 'NG'},
                                                        {'label': 'OK', 'value': 'OK'},
                                                        {'label': '수정완료', 'value': '수정완료'}
                                                    ],
                                                    value='',
                                                    style={'margin-bottom': '10px'}
                                                ),
                                                width=4  
                                            ),
                                            dbc.Col(  
                                                dcc.Dropdown(  
                                                    id='select-model',
                                                    options=[
                                                        {'label': '모델명 선택', 'value': '', 'disabled': True},
                                                        {'label': '전체', 'value': '전체'},
                                                        {'label': 'HZG', 'value': 'HZG'},
                                                        {'label': 'LJLHEV', 'value': 'LJLHEV'},
                                                        {'label': 'LJLICE', 'value': 'LJLICE'}
                                                    ],
                                                    value='',
                                                    style={'margin-bottom': '10px'}
                                                ),
                                                width=4  
                                            ),
                                            dbc.Col(  
                                                dcc.Input(  
                                                    id='select-grab',
                                                    type='text',
                                                    placeholder='GRAB 값을 입력하세요',
                                                    style={'margin-bottom': '10px'}
                                                ),
                                                width=4  
                                            ),
                                        ]),
                                        dbc.Row(
                                            [
                                                dbc.Col(
                                                    dbc.Button("조회", id="submit-date", className="mr-2"),
                                                    width=6
                                                ),
                                                dbc.Col(
                                                    dbc.Button("수정", id="modify-button", className="btn-lg btn-block"),
                                                    width=6
                                                ),
                                            ],
                                            style={'margin-top': '10px'}
                                        )
                                    ],
                                    width=8
                                ),
                                dbc.Col(
                                    html.Div(
                                        id='additional-info',
                                        style={
                                            'border': '1px solid black',
                                            'height': '300px',
                                            'width': '300px',
                                            'padding': '10px'
                                        }
                                    ),
                                    width=4
                                )
                            ]
                        ),
                        dbc.Row(
                            dbc.Col(
                                dash_table.DataTable(
                                    id='modal-output',
                                    columns=[{'name': i, 'id': i, 'editable': (i == '양불')} for i in ['시간', '모델명', 'Trim No', 'grab', '양불', '원본', '빨간박스']],
                                    style_cell=cell_style,
                                    style_table={'overflowX': 'auto','overflowY': 'auto','max-height': '400px'}  
                                ),
                            )
                        ),
                        dbc.Row(  
                            dbc.Col(
                                dcc.RadioItems(
                                    id='select-options',
                                    options=[
                                        {'label': '체크됨', 'value': 'checked'},
                                        {'label': '체크안됨', 'value': 'unchecked'}
                                    ],
                                    value='unchecked',  # 기본값 '체크안됨'
                                    inline=True  
                                ),
                                width=12
                            ),
                            style={'margin-bottom': '10px'}
                        ),
                    ]
                ),
                dbc.ModalFooter(
                    dbc.Button("Close", id="close_main-modal", className="ml-auto")
                ),
            ],
            id="main-modal",
            size="xl"
        ),
    ]
)


# GRAB 값을 받아오는 콜백 함수
@app.callback(
    Output('select-grab', 'value'),
    [Input('main-modal', 'is_open')],
    [State('select-grab', 'value')]
)
def update_grab_input(is_open, current_value):
    if is_open and current_value is None:
        # 모달이 열릴 때 기존 값이 없으면 초기값 설정
        return 'GRAB값 (ex: 전체 , 1R1)'
    else:
        return current_value


# 검사방식 모달부분
검사방법 = html.Div([
    dbc.Button("검사방식", id="open-inspect-modal", n_clicks=0),
    dbc.Modal(
        [
            dbc.ModalHeader(dbc.ModalTitle("검사방식 선택")),
            dbc.ModalBody([
                html.Div([
                    dcc.Dropdown(
                        id='model-dropdown',
                        options=[
                            {'label': '모델', 'value': '', 'disabled': True},
                            {'label': 'HZG', 'value': 'HZG'},
                            {'label': 'LJLHEV', 'value': 'LJLHEV'},
                            {'label': 'LJLICE', 'value': 'LJLICE'},
                        ],
                        value='',
                        style={'margin-right': '10px', 'width': '150px'}
                    ),
                    dcc.Dropdown(
                        id='GRAB-dropdown',
                        options=[
                            {'label': 'GRAB', 'value': '', 'disabled': True}
                        ] + [{'label': str(i), 'value': str(i)} for i in range(1, 11)],
                        value='',
                        style={'margin-right': '10px', 'width': '150px'}
                    ),
                    dcc.Dropdown(
                        id='roi-dropdown',
                        options=[
                            {'label': 'ROI', 'value': '', 'disabled': True}
                        ] + [{'label': str(i), 'value': 'R'+str(i)} for i in range(1, 11)],
                        value='',
                        style={'margin-right': '10px', 'width': '150px'}
                    ),
                    dcc.Dropdown(
                        id='option-dropdown',
                        options=[
                            {'label': '검사방식', 'value': '', 'disabled': True},
                            {'label': 'D', 'value': 'D'},
                            {'label': 'C', 'value': 'C'},
                            {'label': 'FC', 'value': 'FC'},
                            {'label': '없음', 'value': ''}
                        ],
                        value='',
                        style={'margin-right': '10px', 'width': '150px'}
                    ),
                    html.Button('JSON 파일 생성', id='generate-json-button', style={'width': '150px'}),
                    html.Div(id='json-output')
                ], style={'display': 'flex', 'justify-content': 'space-between'})
            ]),
            dbc.ModalFooter(
                dbc.Button("닫기", id="close-insepect-modal", className="ml-auto")
            )
        ],
        id="inspect-modal",
        size="xl",
        is_open=False
    )
])


@app.callback(
    Output("inspect-modal", "is_open"),
    [Input("open-inspect-modal", "n_clicks"), Input("close-insepect-modal", "n_clicks")],
    [State("inspect-modal", "is_open")]
)
def toggle_modal(n1, n2, is_open):
    if n1 or n2:
        return not is_open
    return is_open

@app.callback(
    Output('json-output', 'children'),
    [Input('generate-json-button', 'n_clicks')],
    [State('model-dropdown', 'value'),
     State('GRAB-dropdown', 'value'),
     State('roi-dropdown', 'value'),
     State('option-dropdown', 'value')]
)
def create_json_file(n_clicks, model, GRAB, roi, option):
    if n_clicks is not None:
        folder_name = f"{model}_{GRAB}{roi}"
        folder_path = rf"C:\Renault code\Real_Renault\select 제이슨\{model}\{folder_name}"
        
        # Create folder if it does not exist
        if not os.path.exists(folder_path):
            os.makedirs(folder_path)
        
        # Create JSON file with data
        json_data = {"option": option}
        json_file_path = os.path.join(folder_path, "data.json")
        with open(json_file_path, "w") as json_file:
            json.dump(json_data, json_file)
        
        # Return message
        return "파일이 생성되었습니다."

    
# ROI 설정 레이아웃
ROI설정 = html.Div([
    dcc.Dropdown(
        id='model-dropdown-roi',
        options=[
        {'label': '모델', 'value': '', 'disabled': True},
        {'label': 'HZG', 'value': 'HZG'},
        {'label': 'LJLHEV', 'value': 'LJLHEV'},
        {'label': 'LJLICE', 'value': 'LJLICE'},],
        value='',
        style={'margin-right': '10px', 'width': '150px'}),
    dcc.Dropdown(
        id='GRAB-dropdown-roi',
        options=[
        {'label': 'GRAB', 'value': '', 'disabled': True}] + [{'label': str(i), 'value': str(i)} for i in range(1, 11)],
        value='',
        style={'margin-right': '10px', 'width': '150px'}),
    dcc.Dropdown(
        id='roi-dropdown-roi',
        options=[
        {'label': 'ROI', 'value': '', 'disabled': True}] + [{'label': str(i), 'value': 'R'+str(i)} for i in range(1, 11)],
        value='',
        style={'margin-right': '10px', 'width': '150px'}),
    dcc.Dropdown(
        id='option-dropdown-roi',
        options=[
        {'label': 'Detection 수', 'value': '', 'disabled': True}] + [{'label': str(i), 'value': str(i)} for i in range(1, 31)],
        value='',
        style={'margin-right': '10px', 'width': '150px'}
    ),
    html.Button('디텍션 갯수 결정', id='detection_number', style={'width': '150px'}),
    html.Div(style={'width': '10px'}),  # 세 번째 간격
    html.Button('ROI 영역 설정', id='run_button'),
    html.Div(id='output_div')
], style={'display': 'flex', 'justify-content': 'center', 'align-items': 'center'})

# 디텍션 수 버튼 콜백 함수
@app.callback(
    Output('detection_output_div', 'children'),  # 새로운 Div를 사용하여 출력을 분리합니다.
    [Input('detection_number', 'n_clicks')],
    [State('model-dropdown-roi', 'value'),
     State('GRAB-dropdown-roi', 'value'),
     State('roi-dropdown-roi', 'value'),
     State('option-dropdown-roi', 'value')]
)
def handle_detection_click(n_clicks_detection, model_dropdown_value, GRAB_dropdwon_value, roi_dropdown_value, option_dropdown_value):
    if n_clicks_detection is not None:  # 디텍션 수 버튼이 클릭된 경우
        # 디렉토리 경로 설정
        directory = "C:\\Renault code\\Real_Renault\\디텍션 갯수"
        # 디렉토리가 존재하지 않으면 생성
        if not os.path.exists(directory):
            os.makedirs(directory)
        # JSON 파일 경로 설정
        json_file_path = os.path.join(directory, f'detection_number_{model_dropdown_value}_{GRAB_dropdwon_value}{roi_dropdown_value}.json')
        # 데이터 저장
        data = {'model_dropdown_value': f'{model_dropdown_value}_{GRAB_dropdwon_value}{roi_dropdown_value}' , 'option_dropdown_value': option_dropdown_value}
        with open(json_file_path, 'w') as f:
            json.dump(data, f)
        return ''
    else:
        return ''

# ROI 영역 설정 버튼 콜백 함수
@app.callback(
    Output('roi_output_div', 'children'),  # 새로운 Div를 사용하여 출력을 분리합니다.
    [Input('run_button', 'n_clicks')]
)
def handle_roi_click(n_clicks_run):
    if n_clicks_run is not None:  # ROI 영역 설정 버튼이 클릭된 경우
        # 파이썬 스크립트 실행
        subprocess.Popen(['python', 'C:\Renault code\MAKE ROI.py'])
        return ''
    else:
        return ''

# 상단 섹션 추가
top_section1 = dbc.Row([
    dbc.Col(html.Div("검사 시작", style={'height': '50px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'}), width=1),
    dbc.Col(html.Div("검사 종료", style={'height': '50px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'}), width=1),
    dbc.Col(html.Div(검사방법, style={'height': '50px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'}), width=2),
    dbc.Col(html.Div(ROI설정, style={'height': '50px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'}), width=8)
], style={'height': '50px','border': '0.5px solid black'})

# 상단 섹션에 새로운 Div 추가
top_section_with_output = html.Div([
    top_section1,
    html.Div(id='detection_output_div'),  # 디텍션 수 버튼 콜백 함수의 출력을 표시할 Div
    html.Div(id='roi_output_div')  # ROI 영역 설정 버튼 콜백 함수의 출력을 표시할 Div
])
# 하단 섹션 추가
top_section2 = dbc.Row([
    dbc.Col(html.Div("부저 ON", style={'height': '50px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'})),
    dbc.Col(html.Div("부저 OFF", style={'height': '50px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'})),
    dbc.Col(html.Div( modal , style={'height': '50px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'})),
    dbc.Col(html.Div("종료", style={'height': '50px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'}))
], style={'height': '50px','border': '0.5px solid black'})

# 모달 토글 콜백
@app.callback(
    Output("main-modal", "is_open"),
    [Input("open_main-modal", "n_clicks"), Input("close_main-modal", "n_clicks")],
    [State("main-modal", "is_open")],
)

def toggle_modal(open_clicks, close_clicks, is_open):
    if open_clicks or close_clicks:
        return not is_open
    return is_open

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
#id no 기준으로 가져오기
def get_max_trim_redboximage_names():
    """
    MSSQL 데이터베이스에서 'Id' 열 값이 가장 높은 행의 'Id', 'redboximage_name' 및 'ModelName' 열 값을 가져오는 함수.
    동일한 'Id' 값이 있을 경우 각 행의 'Id','redboximage_name' 및 'ModelName' 값을 모두 반환.
    
    :return: (Id, redboximage_names, model_names)의 튜플
    """
    # 데이터베이스 연결 설정
    server = '주건우의노트북'
    database = '르노코리아실전'
    table = 'DetectedObjects'
    
    connection_string = (
        f'DRIVER={{ODBC Driver 17 for SQL Server}};'
        f'SERVER={server};'
        f'DATABASE={database};'
        f'Trusted_Connection=yes;'
    )

    # 데이터베이스 연결
    conn = pyodbc.connect(connection_string)
    cursor = conn.cursor()

    # "id" 열 값이 가장 높은 행들의 "redboximage_name" 및 "ModelName" 열 값 가져오기
    query = f"""
        SELECT Id, redboximage_name, ModelName
        FROM {table}
        WHERE Id = (SELECT MAX(Id) FROM {table})
    """
    cursor.execute(query)

    # 결과 가져오기
    result = cursor.fetchall()
    max_id = [row[0] for row in result]  # 첫 번째 열은 Id 값입니다.
    redboximage_names = [row[1] for row in result]
    model_names = [row[2] for row in result]

    # 데이터베이스 연결 종료
    cursor.close()
    conn.close()

    # 데이터 가공
    modified_model_names = []
    for name in model_names:
        parts = name.split("\\")
        if len(parts) > 1:
            third_part = parts[2]
            modified_name = third_part.split("_")[0]
            modified_model_names.append(modified_name)
        else:
            modified_model_names.append(name)

    return max_id, redboximage_names, modified_model_names



# 왼쪽 섹션 추가
left_side = dbc.Col([ 
    top_section_with_output,
    html.Div([
        # 행 선택 드롭다운
        html.Div([
            html.Label('행 선택:', style={'margin-right': '10px'}),  # 행 선택 라벨
            dcc.Dropdown(
                id='rows-dropdown',
                options=[
                    {'label': str(i), 'value': i} for i in range(1, 11)  # 1부터 10까지의 행 선택 옵션
                ],
                value=5,  # 기본값은 5로 설정
                style={'width': '200px'}  # 드롭다운 박스의 너비를 200픽셀로 설정
            ),
        ], style={'display': 'inline-block', 'margin-right': '20px', 'vertical-align': 'top'}),  # 가로로 정렬 및 간격 설정
        
        # 열 선택 드롭다운 및 frame-box
        html.Div([
            # 열 선택 드롭다운
            html.Div([
                html.Label('열 선택:', style={'margin-right': '30px'}),  # 열 선택 라벨
                dcc.Dropdown(
                    id='cols-dropdown',
                    options=[
                        {'label': str(i), 'value': i} for i in range(1, 11)  # 1부터 10까지의 열 선택 옵션
                    ],
                    value=5,  # 기본값은 5로 설정
                    style={'width': '200px'}  # 드롭다운 박스의 너비를 200픽셀로 설정
                ),
            ], style={'display': 'inline-block', 'margin-right': '20px', 'vertical-align': 'top'}),  # 가로로 정렬 및 간격 설정
            
            # frame-box
            html.Div(
                id='frame-box',
                style={
                    'width': '300px',
                    'height': '50px',
                    'background-color': 'transparent',
                    'border': '5px solid red',
                    'display': 'inline-block',
                    'vertical-align': 'top',
                    'margin-top': '10px'
                    
                
                }
            ),
             # trim-box
            html.Div(
                id='trim-box',
                style={
                    'width': '300px',
                    'height': '50px',
                    'background-color': 'transparent',
                    'border': '5px solid red',
                    'display': 'inline-block',
                    'vertical-align': 'top',
                    'margin-top': '10px'
                    
                
                }
            )
        ], style={'display': 'inline-block', 'vertical-align': 'top'})  # 가로로 정렬하고 상단 정렬
    ]),
    html.Div(id='output-box', style={'width': '100%', 'height': '100%'})  # 결과 출력 박스
])

@app.callback(
    Output('output-box', 'children'),
    [Input('rows-dropdown', 'value'),
     Input('cols-dropdown', 'value'),
     Input('interval-component', 'n_intervals')]
)
def update_output(rows, cols, n_intervals):
    _, redboximage_names, _  = get_max_trim_redboximage_names()  # redboximage_names만 가져옴

    # 박스 스타일 설정
    box_style = {
        'display': 'grid',
        'grid-template-rows': f"repeat({rows}, minmax(0, 1fr))",  # 박스 내부 구역의 행 크기 설정
        'grid-template-columns': f"repeat({cols}, minmax(0, 1fr))",  # 박스 내부 구역의 열 크기 설정
        'width': '1500px',  # 박스의 너비를 고정
        'height': '700px',   # 박스의 높이를 고정
        'background-color': 'black',
        'border': '5px solid green'
    }

    # 박스 내부 구역 스타일 설정
    box_children = []
    for i in range(rows * cols):
        if i < len(redboximage_names):
            img_path = redboximage_names[i]
            # 이미지를 base64로 인코딩
            with open(img_path, 'rb') as f:
                img_data = base64.b64encode(f.read()).decode('utf-8')
            # 박스의 너비와 높이를 퍼센트로 계산하여 이미지 크기 설정
            img_style = {'width': '100%', 'height': '100%'}
            # 이미지를 HTML img 태그로 변환하여 리스트에 추가
            box_children.append(html.Img(src=f'data:image/png;base64,{img_data}', style=img_style))
        else:
            # 파일이 부족한 경우에는 빈 박스로 처리
            box_children.append(html.Div(style={'border': '1px solid green', 'width': '100%', 'height': '100%'}))

    return html.Div(style=box_style, children=box_children)

@app.callback(
    Output('frame-box', 'children'),
    [Input('interval-component', 'n_intervals')]
)
# update_frame_box 함수 수정
def update_frame_box(n_intervals):
    _, _, model_names = get_max_trim_redboximage_names()  # model_names를 가져옴
    if model_names:
        return html.Div(f"ModelName: {model_names[-1]}", style={'font-size': '20px', 'font-weight': 'bold', 'text-align': 'center'})  # 텍스트 크기, 굵기, 가운데 정렬 지정
    else:
        return ""
@app.callback(
    Output('trim-box', 'children'),
    [Input('interval-component', 'n_intervals')]
)
def update_trim_box(n_intervals):
    max_id, _, _ = get_max_trim_redboximage_names()  # 'max_id' 데이터를 가져옴

    if max_id:
        return html.Div(f"trim No: {max_id[-1]}", style={'font-size': '20px', 'font-weight': 'bold', 'text-align': 'center'})
    else:
        return ""

# 스타일 설정
table_style = {
    'border': '1px solid black',
    'border-collapse': 'collapse',
    'width': '100%',  # 표의 가로 크기를 100%로 설정하여 부모 요소에 맞춤
    'overflowY': 'auto',  # 세로 스크롤바를 표시
    'table-layout': 'auto',  # 각 열의 크기를 데이터에 맞게 자동으로 조정
    'margin-right': '10px',  # 오른쪽 마진 추가
    'textAlign': 'center'
}

header_style = {
    'border': '1px solid black',
    'padding': '2px',
    'backgroundColor': 'lightgray',
    'text-align': 'center'
}

cell_style = {
    'border': '1px solid black',
    'padding': '2px'
}

# 표와 스크롤을 감싸는 div의 스타일 설정
table_scroll_style = {
    'overflowX': 'auto',  # 가로 스크롤 표시
    'overflowY': 'auto',  # 세로 스크롤 표시
}


# Decide 값에 따라 셀 스타일을 설정하는 함수
def style_cell(Decide):
    if Decide == "NG":
        return {'color': 'red', 'font-weight': 'bold', 'border': '1px solid black', 'padding': '2px', 'text-align': 'center'}
    elif Decide == "OK":
        return {'color': 'black', 'border': '1px solid black', 'padding': '2px', 'text-align': 'center'}
    else:
        return {'color': 'black', 'border': '1px solid black', 'padding': '2px', 'text-align': 'center'}

# 오른쪽 섹션 추가
right_side = dbc.Col([
    top_section2,
    html.Div(
        style={'height': '800px', 'width': '450px', 'display': 'flex'},
        children=[
            html.Div(
                id='table-container',
                style=table_scroll_style,
                children=[]
            ),
            html.Div(style={'flex': '1'}),
            html.Div(style={'width': '10px'}),
        ]
    )
])

@app.callback(
    Output('table-container', 'children'),
    [Input('interval-component2', 'n_intervals')]
)
def update_table(n):
    # MSSQL 서버에 연결
    conn = pyodbc.connect('DRIVER={SQL Server};SERVER=주건우의노트북;DATABASE=르노코리아실전;Trusted_Connection=yes;')

    # SQL 쿼리 실행 및 데이터 가져오기 (원하는 열만 선택)
    query = "SELECT Id, DetectedAt, ModelName, Decide FROM DetectedObjects"
    df = pd.read_sql(query, conn)

    # DetectedAt 열의 값을 YYYY년MM월DD일 hh:mm:ss 형식으로 변환
    df['DetectedAt'] = pd.to_datetime(df['DetectedAt']).dt.strftime('%Y년%m월%d일 %H:%M:%S')

    # ModelName 데이터를 "_"를 기준으로 분리하여 첫 번째 파트와 두 번째 파트를 가져옴
    df['ModelName'] = df['ModelName'].apply(lambda x: x.split('_')[0][14:] + '-' + x.split('_')[1])

    # 새로운 열을 추가하여 ModelName 열 왼쪽에 번호를 붙이는 함수 정의
    def add_numbering(row_index):
        return row_index + 1

    # 새로운 열을 추가하여 ModelName 열 왼쪽에 번호를 붙임
    df.insert(0, 'No', df.index.map(add_numbering))
    
    # Id 열의 이름을 Trim No로 변경
    df.rename(columns={'Id': 'Trim No'}, inplace=True)

    # Trim No 열을 Decide 열 왼쪽으로 이동
    cols = df.columns.tolist()
    cols.remove('Trim No')
    cols.insert(cols.index('Decide'), 'Trim No')
    df = df[cols]

    # 데이터프레임을 HTML 테이블로 변환
    table = html.Table(
        # 데이터프레임의 열 이름을 헤더로 사용
        [html.Tr([html.Th(col, style=header_style) for col in df.columns])] +
        # 각 행의 데이터를 테이블에 추가
        [html.Tr([html.Td(df.iloc[i][col], style=style_cell(df.iloc[i]['Decide'])) if col == 'Decide' else html.Td(df.iloc[i][col], style=cell_style) for col in df.columns]) for i in range(len(df))],
        style=table_style
    )

    return table




# 왼쪽과 오른쪽을 하나의 행으로 배치
app.layout = dbc.Row([
    left_side,
    right_side,
    dcc.Interval(
        id='interval-component',
        interval=2*1000,  # 2초마다 업데이트 (밀리초 단위로 지정)
        n_intervals=0),  # 초기값 설정
    dcc.Interval(
            id='interval-component2',
            interval=10*1000,  # milliseconds
            n_intervals=0
        )        
])  # 메인 레이아웃에 ID 추가

# 애플리케이션 실행
if __name__ == '__main__':
    app.run_server(debug=True)