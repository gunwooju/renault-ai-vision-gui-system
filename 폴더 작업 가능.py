import pyodbc
import pandas as pd
import dash
import dash_core_components as dcc
import dash_html_components as html

# MSSQL 서버에 연결
conn = pyodbc.connect('DRIVER={SQL Server};SERVER=주건우의노트북;DATABASE=르노코리아실전;Trusted_Connection=yes;')
cursor = conn.cursor()

# SQL 쿼리 실행 및 데이터 가져오기
query = "SELECT * FROM DetectedObjects;"  # DetectedObjects 테이블에서 모든 열 가져오기
df = pd.read_sql(query, conn)

# 드롭다운 옵션 설정
dropdown_options = [{'label': 'OK', 'value': 'OK'},
                    {'label': 'NG', 'value': 'NG'},
                    {'label': '수정완료', 'value': '수정완료'}]

# Dash 애플리케이션 설정
app = dash.Dash(__name__)

# 각 행에 대한 드롭다운을 포함한 HTML 테이블 생성
def generate_table(dataframe):
    rows = []
    for index, row in dataframe.iterrows():
        # 각 행의 decide 열 값으로 드롭다운 생성
        dropdown = dcc.Dropdown(
            id=f'dropdown-{index}',
            options=dropdown_options,
            value=row['decide'],  # 각 행의 decide 열 값으로 드롭다운 초기값 설정
            clearable=False
        )
        # 각 행의 모든 데이터를 테이블에 추가
        row_data = [html.Td(value) for value in row]
        row_data[-1] = html.Td(dropdown)  # 마지막 열을 드롭다운으로 대체
        rows.append(html.Tr(row_data))
    return html.Table([
        html.Thead(html.Tr([html.Th(col) for col in dataframe.columns])),  # 테이블 헤더 추가
        html.Tbody(rows)
    ])

app.layout = html.Div([
    generate_table(df)
])

if __name__ == '__main__':
    app.run_server(debug=True)
