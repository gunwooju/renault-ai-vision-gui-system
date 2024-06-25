import os
import time
import shutil
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

class NewFileHandler(FileSystemEventHandler):
    def __init__(self, src_folder, dest_folder):
        self.src_folder = src_folder
        self.dest_folder = dest_folder

    def get_next_file_number(self):
        file_list = [f for f in os.listdir(self.src_folder) if os.path.isfile(os.path.join(self.src_folder, f))]
        return len(file_list)

    def on_created(self, event):
        if event.is_directory:
            return
        file_number = self.get_next_file_number()
        src_filename = event.src_path
        filename, file_extension = os.path.splitext(os.path.basename(src_filename))
        new_filename = f"{filename[:-2]}_{file_number}{filename[-2:]}{file_extension}"
        dest_filename = os.path.join(self.dest_folder, new_filename)
        shutil.copy2(src_filename, dest_filename)
        print(f"Copied {src_filename} to {dest_filename}")
        # 파일 시스템 이벤트 처리 후 1초 지연
        time.sleep(0.1)

def main():
    src_folder = r"C:\Renault code\Real_Renault\이게 진짜 최초이미지"
    dest_folder = r"C:\Renault code\Real_Renault\진짜 최초이미지"
    event_handler = NewFileHandler(src_folder, dest_folder)
    observer = Observer()
    observer.schedule(event_handler, src_folder, recursive=False)
    observer.start()
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()

if __name__ == "__main__":
    main()
