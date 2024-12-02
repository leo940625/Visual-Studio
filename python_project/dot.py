import cv2
import mediapipe as mp
import numpy as np
import os

# 計算兩向量夾角
def calculate_angle(point1, point2, point3):
    v1 = np.array([point1.x - point2.x, point1.y - point2.y, point1.z - point2.z])
    v2 = np.array([point3.x - point2.x, point3.y - point2.y, point3.z - point2.z])
    cosine_angle = np.dot(v1, v2) / (np.linalg.norm(v1) * np.linalg.norm(v2))
    angle = np.degrees(np.arccos(np.clip(cosine_angle, -1.0, 1.0)))
    return angle

mp_drawing = mp.solutions.drawing_utils
mp_drawing_styles = mp.solutions.drawing_styles
mp_holistic = mp.solutions.holistic

video_path = 'D:\\Visual-Studio\\Visual-Studio\\python project\\baseball.mp4'

if not os.path.exists(video_path):
    print("影片檔案不存在！")
    exit()

cap = cv2.VideoCapture(video_path)

with mp_holistic.Holistic(
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5) as holistic:
    
    if not cap.isOpened():
        print("無法開啟影片！")
        exit()

    while True:
        ret, img = cap.read()
        if not ret:
            print("影片已播放完畢！")
            break

        img = cv2.resize(img, (720, 1280))
        results = holistic.process(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))

        if results.pose_landmarks:
            # 左膝蓋的角度
            left_hip = results.pose_landmarks.landmark[mp_holistic.PoseLandmark.LEFT_HIP]
            left_knee = results.pose_landmarks.landmark[mp_holistic.PoseLandmark.LEFT_KNEE]
            left_ankle = results.pose_landmarks.landmark[mp_holistic.PoseLandmark.LEFT_ANKLE]
            left_knee_angle = calculate_angle(left_hip, left_knee, left_ankle)

            # 在影像上顯示角度
            cv2.putText(img, f'Left Knee Angle: {int(left_knee_angle)}',
                        (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)

            # 顯示關節點
            mp_drawing.draw_landmarks(
                img,
                results.pose_landmarks,
                mp_holistic.POSE_CONNECTIONS,
                landmark_drawing_spec=mp_drawing_styles
                .get_default_pose_landmarks_style())

        cv2.imshow('Mediapipe Holistic', img)
        if cv2.waitKey(5) == ord('q'):
            break

cap.release()
cv2.destroyAllWindows()
