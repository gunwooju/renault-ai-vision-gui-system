import matplotlib
matplotlib.use('Agg')  # 백엔드 변경
import os
import pyodbc
import pandas as pd
import dash
from dash import html
import dash_bootstrap_components as dbc
import base64
from PIL import Image
import json
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import io
from dash.dependencies import Input, Output, State
from dash import dcc
import time
import winsound  # for sound alarm
import re
import subprocess

# MSSQL 연결 정보
server = '주건우의노트북'
database = '르노코리아'
conn_str = f'DRIVER=SQL Server;SERVER={server};DATABASE={database};Trusted_Connection=yes;'

# 함수 정의: 최신 이미지 경로 및 박스 정보 가져오기
def get_latest_image_and_boxes(table_prefix):
    conn = pyodbc.connect(conn_str)
    cursor = conn.cursor()
     
    query = f"SELECT TOP (1) [이미지경로] FROM [dbo].[name_and_image{table_prefix}] ORDER BY [시간] DESC;"
    cursor.execute(query)
    latest_row = cursor.fetchone()
    image_path = latest_row[0]

    cursor.execute(f"SELECT * FROM firstbox{table_prefix} ORDER BY 시간 DESC;")
    box_info_1 = cursor.fetchone()
    cursor.execute(f"SELECT * FROM secondbox{table_prefix} ORDER BY 시간 DESC;")
    box_info_2 = cursor.fetchone()

    cursor.close()
    conn.close()

    return image_path, box_info_1, box_info_2

# 함수 정의: 이미지에 박스 그리기
def draw_boxes_on_image(image_path, box_data, output_path):
    image = Image.open(image_path)
    fig, ax = plt.subplots()
    ax.imshow(image)
    ax.axis('off')

    for box_info in box_data:       
        width = box_info[4]
        height = box_info[5]
        center_x = box_info[2]
        center_y = box_info[3]
        x = center_x - width / 2
        y = center_y - height / 2

        rect = patches.Rectangle((x, y), width, height, linewidth=1, edgecolor='r', facecolor='none')
        ax.add_patch(rect)

    plt.savefig(output_path, format='png')
    plt.close(fig)

    with open(output_path, "rb") as img_file:
        encoded_image = base64.b64encode(img_file.read()).decode('ascii')

    return f"data:image/png;base64,{encoded_image}"

# 함수 정의: 최신 박스 데이터 가져오기
def get_latest_box_data(table_prefix, reading_table_prefix):
    conn = pyodbc.connect(conn_str)
    cursor = conn.cursor()

    cursor.execute(f"SELECT TOP (1) classindex00, classindex01, 시간 FROM firstbox_reading{table_prefix} ORDER BY 시간 DESC;")
    first_box_data = cursor.fetchone()

    cursor.execute(f"SELECT TOP (1) classindex10, classindex11, 시간 FROM secondbox_reading{table_prefix} ORDER BY 시간 DESC;")
    second_box_data = cursor.fetchone()

    cursor.close()
    conn.close()

    return first_box_data, second_box_data

# 데이터 가져오는 함수
def fetch_latest_data():
    conn = pyodbc.connect(conn_str)
    cursor = conn.cursor()

    # 최신 100개의 데이터 가져오기
    query = """
    SELECT TOP 100 
        CASE 
            WHEN source_table = 'firstbox_reading1' THEN '구역 1 첫번째 박스'
            WHEN source_table = 'firstbox_reading2' THEN '구역 2 첫번째 박스'
            WHEN source_table = 'firstbox_reading3' THEN '구역 3 첫번째 박스'
            WHEN source_table = 'secondbox_reading1' THEN '구역 1 두번째 박스'
            WHEN source_table = 'secondbox_reading2' THEN '구역 2 두번째 박스'
            WHEN source_table = 'secondbox_reading3' THEN '구역 3 두번째 박스'
            ELSE ''
        END AS 설명,
        classindex AS 일치율, 
        FORMAT(시간, 'yyyy-MM-dd HH:mm:ss') AS 시간
    FROM (
        SELECT classindex01 AS classindex, 시간, 'firstbox_reading1' AS source_table FROM firstbox_reading1 WHERE classindex01 <= 0.85
        UNION ALL
        SELECT classindex01 AS classindex, 시간, 'firstbox_reading2' AS source_table FROM firstbox_reading2 WHERE classindex01 <= 0.85
        UNION ALL
        SELECT classindex01 AS classindex, 시간, 'firstbox_reading3' AS source_table FROM firstbox_reading3 WHERE classindex01 <= 0.85
        UNION ALL
        SELECT classindex11 AS classindex, 시간, 'secondbox_reading1' AS source_table FROM secondbox_reading1 WHERE classindex11 <= 0.85
        UNION ALL
        SELECT classindex11 AS classindex, 시간, 'secondbox_reading2' AS source_table FROM secondbox_reading2 WHERE classindex11 <= 0.85
        UNION ALL
        SELECT classindex11 AS classindex, 시간, 'secondbox_reading3' AS source_table FROM secondbox_reading3 WHERE classindex11 <= 0.85
    ) AS combined_data
    ORDER BY 시간 DESC
    """
    cursor.execute(query)
    rows = cursor.fetchall()

    df = pd.DataFrame([tuple(row) for row in rows], columns=[desc[0] for desc in cursor.description])

    cursor.close()
    conn.close()

    return df

# 알람 소리 경로
alarm_sound_path = "C:/르노코리아 코딩연습/assets/warning.wav"

# 알람 함수 정의
def sound_alarm():
    winsound.PlaySound(alarm_sound_path, winsound.SND_FILENAME)

# 알람 기능 구현
def check_alarm():
    triggered_area = None
    for i in range(1, 4):
        for j in range(1, 4):
            first_box_data, second_box_data = get_latest_box_data(str(i), str(j))

            print("First Box Data:", first_box_data)
            print("Second Box Data:", second_box_data)

            if first_box_data[1] <= 0.85 or second_box_data[1] <= 0.85:
                sound_alarm()
                triggered_area = f"{i}-{j}"
                print("Alarm activated!")
                break
    return triggered_area

# Dash 애플리케이션 생성
app = dash.Dash(__name__, external_stylesheets=[dbc.themes.BOOTSTRAP])

# 기존에 생성된 JSON 파일 중에서 가장 큰 번호를 찾습니다.
def find_highest_number(directory_path, base_filename):
    max_num = 0
    for filename in os.listdir(directory_path):
        match = re.match(rf"{base_filename}(\d+)\.json", filename)
        if match:
            num = int(match.group(1))
            max_num = max(max_num, num)
    return max_num
검사방법 =  html.Div([dcc.Dropdown(
        id='option-dropdown',
        options=[
            {'label': 'D', 'value': 'D'},
            {'label': 'C', 'value': 'C'},
            {'label': '없음', 'value': ''}
        ],
        value='D'
    ),
    html.Button('검사방법 설정', id='generate-json-button'),
    html.Div(id='json-output')
])

@app.callback(
    Output('json-output', 'children'),
    [Input('generate-json-button', 'n_clicks')],
    [dash.dependencies.State('option-dropdown', 'value')]
)
def create_json_file(n_clicks, option):
    if n_clicks is not None:
        data = {"option": option}
        base_path = "C:/르노코리아 코딩연습/르노코리아 실전/select 제이슨"
        highest_number = find_highest_number(base_path, "selectDC")
        next_filename = f"selectDC{highest_number + 1}"
        file_path = os.path.join(base_path, f"{next_filename}.json")
        with open(file_path, "w") as json_file:
            json.dump(data, json_file)
        return html.Div(f"JSON 파일 '{next_filename}.json'이 생성되었습니다.")

ROI설정 = html.Div([html.Button('ROI영역 설정', id='run_button'),
    html.Div(id='output_div')
])
@app.callback(
    Output('output_div', 'children'),
    [Input('run_button', 'n_clicks')]
)
def run_script(n_clicks):
    if n_clicks is not None:
        # 파이썬 스크립트 실행
        subprocess.Popen(['python', 'C:/르노코리아 코딩연습/MAKE ROI.py'])
        return '파이썬 스크립트가 실행되었습니다.'



# 상단 섹션 추가
top_section1 = dbc.Row([
    dbc.Col(html.Div("검사 시작", style={'height': '100px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'})),
    dbc.Col(html.Div("검사 종료", style={'height': '100px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'})),
    dbc.Col(html.Div(검사방법, style={'height': '100px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'})),
    dbc.Col(html.Div(ROI설정, style={'height': '100px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'}))
], style={'height': '100px','border': '0.5px solid black'})

# 하단 섹션 추가
top_section2 = dbc.Row([
    dbc.Col(html.Div("부저 ON", style={'height': '100px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'})),
    dbc.Col(html.Div("부저 OFF", style={'height': '100px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'})),
    dbc.Col(html.Div("조회", style={'height': '100px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'})),
    dbc.Col(html.Div("종료", style={'height': '100px','border': '0.5px solid black', 'display': 'flex', 'align-items': 'center', 'justify-content': 'center'}))
], style={'height': '100px','border': '0.5px solid black'})

# 왼쪽 섹션 추가
left_side = dbc.Col([ 
    top_section1,
    dbc.Row([
        dbc.Col(html.Div("구역 1", style={'height': '50px', 'background-color': 'green', 'color': 'black', 'text-align': 'center', 'line-height': '50px', 'font-weight': 'bold'})), 
        dbc.Col(html.Div("구역 2", style={'height': '50px', 'background-color': 'green', 'color': 'black', 'text-align': 'center', 'line-height': '50px', 'font-weight': 'bold'})), 
        dbc.Col(html.Div("구역 3", style={'height': '50px', 'background-color': 'green', 'color': 'black', 'text-align': 'center', 'line-height': '50px', 'font-weight': 'bold'})), 
    ], style={'height': '50px', 'border': '0.5px solid black', 'display': 'flex'}), 
    dbc.Row([ 
        dbc.Col(html.Div(html.Img(id='image_1', style={'width': '100%', 'height': 'auto'}), style={'height': 'auto', 'border': '0.5px solid black'}), width=4), 
        dbc.Col(html.Div(html.Img(id='image_2', style={'width': '100%', 'height': 'auto'}), style={'height': 'auto', 'border': '0.5px solid black'}), width=4), 
        dbc.Col(html.Div(html.Img(id='image_3', style={'width': '100%', 'height': 'auto'}), style={'height': 'auto', 'border': '0.5px solid black'}), width=4) 
    ]), 
    dbc.Row([ 
        dbc.Col(html.Div("구역 4", style={'height': '50px', 'background-color': 'green', 'color': 'black', 'text-align': 'center', 'line-height': '50px', 'font-weight': 'bold'})), 
        dbc.Col(html.Div("구역 5", style={'height': '50px', 'background-color': 'green', 'color': 'black', 'text-align': 'center', 'line-height': '50px', 'font-weight': 'bold'})), 
        dbc.Col(html.Div("구역 6", style={'height': '50px', 'background-color': 'green', 'color': 'black', 'text-align': 'center', 'line-height': '50px', 'font-weight': 'bold'})), 
    ], style={'height': '50px', 'border': '0.5px solid black', 'display': 'flex'}), 
    dbc.Row([ 
        dbc.Col(html.Div(html.Img(src='https://via.placeholder.com/200x100', style={'width': '100%', 'height': 'auto'}), style={'height': 'auto', 'border': '0.5px solid black'}), width=4), 
        dbc.Col(html.Div(html.Img(src='https://via.placeholder.com/200x100', style={'width': '100%', 'height': 'auto'}), style={'height': 'auto', 'border': '0.5px solid black'}), width=4), 
        dbc.Col(html.Div(html.Img(src='https://via.placeholder.com/200x100', style={'width': '100%', 'height': 'auto'}), style={'height': 'auto', 'border': '0.5px solid black'}), width=4) 
    ]),
    dbc.Row([ 
        dbc.Col(html.Div("구역 7", style={'height': '50px', 'background-color': 'green', 'color': 'black', 'text-align': 'center', 'line-height': '50px', 'font-weight': 'bold'})), 
        dbc.Col(html.Div("구역 8", style={'height': '50px', 'background-color': 'green', 'color': 'black', 'text-align': 'center', 'line-height': '50px', 'font-weight': 'bold'})), 
        dbc.Col(html.Div("구역 9", style={'height': '50px', 'background-color': 'green', 'color': 'black', 'text-align': 'center', 'line-height': '50px', 'font-weight': 'bold'})), 
    ], style={'height': '50px', 'border': '0.5px solid black', 'display': 'flex'}), 
    dbc.Row([ 
        dbc.Col(html.Div(html.Img(src='https://via.placeholder.com/200x100', style={'width': '100%', 'height': 'auto'}), style={'height': 'auto', 'border': '0.5px solid black'}), width=4), 
        dbc.Col(html.Div(html.Img(src='https://via.placeholder.com/200x100', style={'width': '100%', 'height': 'auto'}), style={'height': 'auto', 'border': '0.5px solid black'}), width=4), 
        dbc.Col(html.Div(html.Img(src='https://via.placeholder.com/200x100', style={'width': '100%', 'height': 'auto'}), style={'height': 'auto', 'border': '0.5px solid black'}), width=4) 
    ])  
])

# 오른쪽 섹션 추가
right_side = dbc.Col([
    top_section2,
    html.Div(id='live-update-table', style={'overflowY': 'auto', 'height': '1000px'})
], width=2)

app.layout = dbc.Row([
    left_side,
    dcc.Interval(id='interval-component', interval=30*1000, n_intervals=0),
    right_side,
    html.Div(id='dummy-output', style={'display': 'none'}),
    html.Div(
        [
            dbc.Modal(
                [
                    dbc.ModalHeader("알람"),
                    dbc.ModalBody(id="modal-body"),
                    dbc.ModalFooter(
                        dbc.Button("확인", id="close", className="ml-auto")
                    ),
                ],
                id="modal",
                is_open=False,
            )
        ]
    )
], id='main-layout')

# 테이블 업데이트 함수
@app.callback(
    dash.dependencies.Output('live-update-table', 'children'),
    [dash.dependencies.Input('interval-component', 'n_intervals')]
)

def update_table(n):
    df = fetch_latest_data()
    table_rows = [
        html.Tr([
            html.Th(col, style={'border': '1px solid black', 'text-align': 'center', 'color': 'red'}) for col in df.columns  # 각 열의 제목을 중앙 정렬 및 테두리 추가 및 빨간색으로 변경
        ])
    ]
    for i in range(len(df)):
        table_rows.append(html.Tr([
            html.Td(df.iloc[i][col], style={'border': '1px solid black', 'text-align': 'center'}) for col in df.columns  # 각 데이터 값을 중앙 정렬 및 테두리 추가
        ]))
        # 데이터 행과 다음 행 사이에 구분선 추가
        if i < len(df) - 1:
            table_rows.append(html.Tr([html.Td(html.Div(style={'border-bottom': '1px solid black'}), colSpan=len(df.columns))]))
    return html.Table(table_rows, style={'border-collapse': 'collapse'})  # 테이블 스타일 지정

# 모달 창 추가
modal = html.Div(
    [
        dbc.Modal(
            [
                dbc.ModalHeader("알람"),
                dbc.ModalBody(id="modal-body"),
                dbc.ModalFooter(
                    dbc.Button("확인", id="close", className="ml-auto")
                ),
            ],
            id="modal",
            is_open=False,
        )
    ]
)

# 레이아웃에 dummy-output 컴포넌트 추가
dummy_output = html.Div(id='dummy-output', style={'display': 'none'})

# 왼쪽과 오른쪽을 하나의 행으로 배치
app.layout = dbc.Row([
    left_side,
    dcc.Interval(id='interval-component', interval=10*1000, n_intervals=0),  # 10초마다 새로고침
    right_side,
    dummy_output,  # dummy-output 컴포넌트 추가
    modal  # 모달 추가
], id='main-layout')  # 메인 레이아웃에 ID 추가

# 알람 기능 콜백 함수
@app.callback(
    Output('dummy-output', 'children'),
    [Input('interval-component', 'n_intervals')]
)
def update_alarm(n_intervals):
    triggered_area = check_alarm()
    if triggered_area:
        print("Alarm triggered for area:", triggered_area)  # 이 부분을 추가하여 함수가 호출되는지 확인
        return triggered_area
    return ""

# 모달 표시 및 내용 업데이트 콜백 함수
@app.callback(
    [Output("modal", "is_open"), Output("modal-body", "children")],
    [Input("dummy-output", "children"), Input("close", "n_clicks")],
    [State("modal", "is_open")],
)
def update_modal(triggered_area, n_clicks, is_open):
    if triggered_area:
        # 구역 정보에서 "-"를 기준으로 분리하여 구역 번호만 가져오기
        triggered_area = triggered_area.split("-")[0]
        new_is_open = True
        modal_content = f"구역 {triggered_area} 불량 발생"
    elif n_clicks is not None and n_clicks > 0:
        new_is_open = False  # 확인 버튼을 누르면 모달 창이 꺼지도록 설정
        modal_content = ""
        # 아래 코드 추가: 확인 버튼을 누르면 모달 창이 꺼지고, 모달 창의 내용도 비워짐
        triggered_area = ""
    else:
        new_is_open = is_open
        modal_content = ""

    return new_is_open, modal_content




# 이미지 업데이트 콜백 함수
@app.callback(
    [Output('image_1', 'src'), Output('image_2', 'src'), Output('image_3', 'src')],
    [Input('interval-component', 'n_intervals')]
)
def update_images(n_intervals):
    image_paths = []
    box_data = []
    for i in range(1, 4):
        image_path, box_info_1, box_info_2 = get_latest_image_and_boxes(str(i))
        image_paths.append(image_path)
        box_data.append([box_info_1, box_info_2])

    image_srcs = []
    for i in range(3):
        output_path = f"output_image_{i+1}.png"
        image_src = draw_boxes_on_image(image_paths[i], box_data[i], output_path)
        image_srcs.append(image_src)

    return tuple(image_srcs)

# 애플리케이션 실행
if __name__ == '__main__':
    app.run_server(debug=True)
