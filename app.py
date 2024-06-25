import subprocess
import time
# 영 번째 파일 실행
subprocess.Popen(["python", "sql2.py"])
 
time.sleep(3)
# 첫 번째 파일 실행
subprocess.Popen(["python", "빨간박스.py"])

# 두 번째 파일 실행
subprocess.Popen(["python", "마지막 분류.py"])

# 두 번째 파일 실행
subprocess.Popen(["python", "연습중.py"])