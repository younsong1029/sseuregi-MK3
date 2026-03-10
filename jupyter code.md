import cv2
import serial
from ultralytics import YOLO

# YOLO 모델 불러오기
model = YOLO("best.pt")

# 아두이노 연결 (COM포트는 PC마다 다름)
ser = serial.Serial('COM3', 9600)

# 카메라 실행
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()

    results = model(frame)

    for r in results:
        for box in r.boxes:
            
            cls = int(box.cls[0])
            label = model.names[cls]

            print(label)

            if label == "plastic":
                ser.write(b'P')

            elif label == "can":
                ser.write(b'C')

            elif label == "paper":
                ser.write(b'A')

            else:
                ser.write(b'G')

    cv2.imshow("YOLO Detection", frame)

    if cv2.waitKey(1) == 27:
        break

cap.release()
cv2.destroyAllWindows()
