import subprocess
import time
# 첫 번째 파일 실행
subprocess.Popen(["python", "폴더생성.py"])

# 두 번째 파일 실행
subprocess.Popen(["python", "마지막 분류.py"])

# 세 번째 파일 실행
subprocess.Popen(["python", "SENDING FILE.py"])

#10초 대기
time.sleep(3)
# 네 번째 파일 실행
subprocess.Popen(["python", "이미지 자르기.py"])

# 다섯 번째 파일 실행
subprocess.Popen(["python", "sql2.py"])
 
time.sleep(3)
# 여섯 번째 파일 실행
subprocess.Popen(["python", "빨간박스.py"])

# 일곱 번째 파일 실행
subprocess.Popen(["python", "이름바꿔 옮기기.py"])

# 여덟 번째 파일 실행
subprocess.Popen(["python", "연습중.py"])

time.sleep(5)
#아홉번째 파일 실행
subprocess.Popen(["python", "알람 함수.py"])
