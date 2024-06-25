import time
from pypylon import pylon
import os
import cv2

def initialize_camera():
    tl_factory = pylon.TlFactory.GetInstance()
    devices = tl_factory.EnumerateDevices()
    if not devices:
        raise pylon.RuntimeException("No camera present.")
    camera = pylon.InstantCamera(tl_factory.CreateDevice(devices[0]))
    camera.Open()
    return camera

def capture_and_save(camera, folder_path, interval=10):
    camera.StartGrabbing(pylon.GrabStrategy_LatestImageOnly)

    while camera.IsGrabbing():
        result = camera.RetrieveResult(5000, pylon.TimeoutHandling_ThrowException)
        
        if result.GrabSucceeded():
            image = result.Array
            
            print(f"Image shape: {image.shape}, dtype: {image.dtype}")
            
            # 이미지가 그레이스케일인지 확인하고, RGB로 변환
            if len(image.shape) == 2 or image.shape[2] == 1:
                image = cv2.cvtColor(image, cv2.COLOR_GRAY2BGR)
            
            filename = os.path.join(folder_path, f"image_{int(time.time())}.png")
            filename = os.path.normpath(filename)  # 경로를 정규화하여 슬래시 문제 해결
            
            success = cv2.imwrite(filename, image)
            if success:
                print(f"Saved image to {filename}")
            else:
                print(f"Failed to save image to {filename}")
        
        time.sleep(interval)

def main():
    camera = initialize_camera()
    
    folder_path = "C:/Renault code/Real_Renault/camera pictures"
    os.makedirs(folder_path, exist_ok=True)
    
    try:
        capture_and_save(camera, folder_path)
    except KeyboardInterrupt:
        camera.StopGrabbing()
        camera.Close()
        print("Camera connection closed.")

if __name__ == "__main__":
    main()
