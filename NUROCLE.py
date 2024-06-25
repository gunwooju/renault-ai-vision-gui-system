import os
import shutil
import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

class MyHandler(FileSystemEventHandler):
    def __init__(self, src_folders, dest_folder):
        self.src_folders = src_folders
        self.dest_folder = dest_folder

    def on_created(self, event):
        if event.is_directory:
            return
        src_path = event.src_path
        for folder in self.src_folders:
            if src_path.startswith(folder):
                dest_path = os.path.join(self.dest_folder, os.path.basename(src_path))
                self.safe_copy(src_path, dest_path)
                break

    def safe_copy(self, src, dest):
        try:
            # 대기 시간 동안 파일이 완전히 쓰여질 때까지 대기
            time.sleep(4)
            shutil.copyfile(src, dest)
            print(f"File '{src}' copied to '{dest}'")
        except Exception as e:
            print(f"Error copying file from '{src}' to '{dest}': {e}")

def watch_folders(src_folders, dest_folder):
    observer = Observer()
    event_handler = MyHandler(src_folders, dest_folder)
    for folder in src_folders:
        observer.schedule(event_handler, folder, recursive=True)
    observer.start()
    try:
        while observer.is_alive():
            observer.join(1)  # Wait for the observer thread to join, checking every 1 second
    except KeyboardInterrupt:
        observer.stop()
        observer.join()

if __name__ == "__main__":
    src_folders = [
        r"C:\Renault code\Real_Renault\ROI(HZG)\GRAB1\ROI1",
        r"C:\Renault code\Real_Renault\ROI(HZG)\GRAB1\ROI2",
        r"C:\Renault code\Real_Renault\ROI(HZG)\GRAB1\ROI3",
        r"C:\Renault code\Real_Renault\ROI(HZG)\GRAB1\ROI4",
        r"C:\Renault code\Real_Renault\ROI(LJLHEV)\GRAB1\ROI1",
        r"C:\Renault code\Real_Renault\ROI(LJLHEV)\GRAB1\ROI2",
        r"C:\Renault code\Real_Renault\ROI(LJLHEV)\GRAB3\ROI1",
        r"C:\Renault code\Real_Renault\ROI(LJLICE)\GRAB1\ROI1",
        r"C:\Renault code\Real_Renault\ROI(LJLICE)\GRAB1\ROI2"
    ]  # Add your source folders here
    dest_folder = r"C:\Renault code\Real_Renault\NUROCLE"  # Specify your destination folder
    watch_folders(src_folders, dest_folder)
