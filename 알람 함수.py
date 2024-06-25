from datetime import datetime, timedelta
import time
import pyodbc
from playsound import playsound
import threading

# 경로를 사용하여 사운드 파일 재생
sound_file_path = r"C:\Renault code\assets\warning.wav"

# MS SQL 서버 연결 설정
server = '주건우의노트북'  # 서버 이름 혹은 IP 주소
database = '르노코리아실전'  # 데이터베이스 이름

def connect_to_database(server, database):
    """ 데이터베이스에 연결을 시도하고 연결 객체를 반환 """
    try:
        conn = pyodbc.connect(f'DRIVER={{SQL Server}};SERVER={server};DATABASE={database};Trusted_Connection=yes;')
        return conn
    except Exception as e:
        print(f"Error connecting to database: {str(e)}")
        with open("error_log.txt", "a") as f:
            f.write(f"Error connecting to database: {str(e)}\n")
        return None

def check_database_for_alarm(conn):
    while True:
        try:
            current_time = datetime.now()
            five_seconds_ago = current_time - timedelta(seconds=60)

            query = "SELECT decide FROM DetectedObjects WHERE DetectedAt BETWEEN ? AND ?"
            params = (five_seconds_ago, current_time)

            cursor = conn.cursor()
            cursor.execute(query, params)
            rows = cursor.fetchall()

            print("Fetched data:")
            for row in rows:
                print(row)

            for row in rows:
                if 'NG' in row.decide:
                    playsound(sound_file_path)
                    print("ng")

            cursor.close()
            time.sleep(5)

        except Exception as e:
            print(f"Error occurred in database query: {str(e)}")
            with open("error_log.txt", "a") as f:
                f.write(f"Error occurred in database query: {str(e)}\n")
            time.sleep(10)

def main():
    conn = connect_to_database(server, database)
    if conn:
        # 별도의 스레드에서 check_database_for_alarm 함수 실행
        thread = threading.Thread(target=check_database_for_alarm, args=(conn,))
        thread.start()
    else:
        print("Failed to connect to the database. Check the connection settings.")

if __name__ == "__main__":
    main()
