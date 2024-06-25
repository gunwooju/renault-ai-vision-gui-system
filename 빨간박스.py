import pyodbc
from PIL import Image, ImageDraw, ImageFont
import os
import time

# MSSQL 서버 연결 정보
server = "주건우의노트북"
database = "르노코리아실전"

# MSSQL 서버에 연결
conn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes;')

# 이전에 가져온 데이터의 DETECTEDAT 시간을 저장할 변수
last_detected_at = None

def fetch_data_from_database():
    global last_detected_at
    
    cursor = conn.cursor()
    if last_detected_at is None:
        # 처음 실행될 때는 가장 최신의 데이터만 가져옴
        cursor.execute('SELECT TOP 1 * FROM DetectedObjects ORDER BY DetectedAt DESC')
    else:
        # 이전에 가져온 데이터 이후의 새로운 데이터만 가져옴
        cursor.execute('SELECT * FROM DetectedObjects WHERE DetectedAt > ?', last_detected_at)
    rows = cursor.fetchall()
    
    # 가져온 데이터 중 가장 최신의 DETECTEDAT 시간을 저장
    if rows:
        last_detected_at = rows[0].DetectedAt
    
    return rows

def draw_boxes_and_save_images(row, output_folder):
    # Load image
    image_path = row.ImageName  # Assuming ImageName contains the path to the image
    image = Image.open(image_path)
    draw = ImageDraw.Draw(image)

    # Define font for text
    font = ImageFont.truetype("arial.ttf", 60)  # Change the font size here
    
    # Extract the first part of the image name
    image_name_parts = os.path.splitext(os.path.basename(image_path))[0].split("_")
    first_part = image_name_parts[1] + "-" + image_name_parts[2] if image_name_parts else ""
    
    model_type_from_image = row.ModelTypeFromImage
    objectx_qty = row.ObjectxQty

    if model_type_from_image == "DETECTION":
        # Draw boxes based on the object quantity
        for i in range(objectx_qty):
            left_top_x = getattr(row, f"LeftTopX{i}")
            left_top_y = getattr(row, f"LeftTopY{i}")
            width = getattr(row, f"Width{i}")
            height = getattr(row, f"Height{i}")
            class_name = getattr(row, f"ClassName{i}")
            value = getattr(row, f"Value{i}")

            # Check if value is greater than or equal to 0.85
            if value >= 0.85:
                # Draw red box
                draw.rectangle([left_top_x, left_top_y, left_top_x + width, left_top_y + height], outline="red", width=30)

                # Write class name and value
                text = f"{class_name}: {value}"
                draw.text((left_top_x + width + 5, left_top_y), text, fill="red", font=font)
                
                # Write the first part of the image name in red at the top left corner
                draw.text((10, 10), first_part, fill="white", font=font)
    
    elif model_type_from_image == "FLOWCHART":
        # Draw single box
        left_top_x = row.LeftTopX0
        left_top_y = row.LeftTopY0
        width = row.Width0
        height = row.Height0
        class_name_0 = row.ClassName0
        value_0 = row.Value0
        class_name_1 = row.ClassName1
        value_1 = row.Value1

        # Check if value_0 is greater than or equal to 0.85
        if value_0 >= 0.85:
            # Draw red box
            draw.rectangle([left_top_x, left_top_y, left_top_x + width, left_top_y + height], outline="red", width=30)

            # Write class name and value
            text_0 = f"{class_name_0}: {value_0}"
            draw.text((left_top_x + width + 5, left_top_y), text_0, fill="red", font=font)
            
            # Write the first part of the image name in red at the top left corner
            draw.text((10, 10), first_part, fill="red", font=font)
        
        # Calculate the position to place text_1
        text_1_position = (left_top_x + width + 5, left_top_y)

        # Calculate the width of text_0
        text_0_bbox = font.getbbox(text_0)
        text_0_width = text_0_bbox[2] - text_0_bbox[0]  # Calculate width from bbox

        # Update X coordinate of text_1_position
        text_1_position = (text_1_position[0] + text_0_width + 5, text_1_position[1])

        # Draw text_1 if value_1 is greater than or equal to 0.85
        if value_1 >= 0.85:
            draw.text(text_1_position, f"{class_name_1}: {value_1}", fill="white", font=font)

    # Save the processed image
    filename = os.path.basename(image_path)
    output_path = os.path.join(output_folder, filename)
    image.save(output_path)

# 5초마다 데이터를 가져와 처리하는 함수 
def process_data_periodically():
    initial_fetch = True  # 처음 실행 여부를 확인하기 위한 변수
    while True:
        # 데이터베이스에서 새로운 데이터 가져오기
        rows = fetch_data_from_database()
        
        # 처음 실행될 때는 박스를 그리지 않음
        if initial_fetch:
            initial_fetch = False
        else:
            # 새로운 데이터가 있는 경우에만 처리
            if rows:
                for row in rows:
                    draw_boxes_and_save_images(row, output_folder)
                    
        # 5초 대기
        time.sleep(3)

# 코드 실행
if __name__ == "__main__":
    output_folder = "C:\\Renault code\\Real_Renault\\박스표시 이미지"  # Backslashes need to be escaped in Python strings
    process_data_periodically()
