import os
import dash
from dash import dcc, html
from dash.dependencies import Input, Output
import base64
from datetime import datetime
# 오늘의 날짜 가져오기
today = datetime.now().strftime("%Y년%m월%d일")

# 웹 애플리케이션 생성
app = dash.Dash(__name__)

# 이미지 파일이 있는 폴더 경로
folder_paths = [r"C:\Renault code\Real_Renault\FINAL IMAGE\HZG\GRAB1\ROI1",
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

# 이미지 파일을 비교하고 결과를 반환하는 함수
def compare_images():
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
                        max_third_part_files = [file]
                    elif third_part_value == max_third_part:
                        max_third_part_files.append(file)
                except ValueError:
                    pass
    return file   
# Z 박스의 레이아웃 설정
def generate_z_box(rows, cols, images):
    # 박스 스타일 설정
    box_style = {
        'display': 'grid',
        'grid-template-rows': f"repeat({rows}, 1fr)",
        'grid-template-columns': f"repeat({cols}, 1fr)",
        'width': '1200px',
        'height': '600px',
        'background-color': 'black'
    }
    # 박스 내부 구역 스타일 설정
    box_children = []
    for i in range(rows * cols):
        if i < len(images):
            box_children.append(html.Img(src=images[i], style={'max-width': '100%', 'max-height': '100%','min-width' : '100%','min-height' : '100%'}))
        else:
            box_children.append(html.Div(f'구역 {i+1}', style={'display': 'flex', 'justify-content': 'center', 'align-items': 'center', 'color': 'white'}))
    return html.Div(style=box_style, children=box_children)

# 대시 애플리케이션 레이아웃 설정
app.layout = html.Div([
    html.H1("Z 박스"),
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
    ], style={'display': 'inline-block', 'margin-right': '20px'}),  # 행 선택 드롭다운 박스와 라벨을 가로로 정렬
    html.Div([
        html.Label('열 선택:', style={'margin-right': '10px'}),  # 열 선택 라벨
        dcc.Dropdown(
            id='cols-dropdown',
            options=[
                {'label': str(i), 'value': i} for i in range(1, 11)  # 1부터 10까지의 열 선택 옵션
            ],
            value=5,  # 기본값은 5로 설정
            style={'width': '200px'}  # 드롭다운 박스의 너비를 200픽셀로 설정
        ),
    ], style={'display': 'inline-block'}),  # 열 선택 드롭다운 박스와 라벨을 가로로 정렬
    html.Div(id='z-box')
])

# 이미지 파일 비교 및 결과 업데이트
@app.callback(
    Output('z-box', 'children'),
    [Input('rows-dropdown', 'value'),
     Input('cols-dropdown', 'value')]
)
def update_z_box(rows, cols):
    max_files = compare_images()
    if max_files:
        images = ['data:image/png;base64,' + base64.b64encode(open(file, 'rb').read()).decode('utf-8') for file in max_files]
        return generate_z_box(rows, cols, images)
    else:
        return html.P("이미지 파일이 없습니다.")

# 애플리케이션 실행
if __name__ == '__main__':
    app.run_server(debug=True)
