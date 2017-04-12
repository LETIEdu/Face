#!/usr/bin/python3
import cv2

# Создание объекта для работы с камерой
cap = cv2.VideoCapture(0)
# Установка разрешения 320*240
cap.set(3, 320)
cap.set(4, 240)
# Создание классификатора и загрузка его параметров из файла
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_alt.xml')

# Бесконечный цикл
while True:
    # Чтение кадра с камеры
    ret, frame = cap.read()
    # Если кадр пустой, то выходим из программы
    if not ret:
        break

    # Ищем лица на изображении с помощью классификатора
    faces = face_cascade.detectMultiScale(frame, 1.15, 3)

    # Цикл по всем лицам, x, y - координаты левого верхнего угла лица
    # width, height - ширина и высота лица
    for (x, y, width, height) in faces:
        # Рисуем прямоугольник вокруг лица на изображении
        cv2.rectangle(frame,  # изображение
                      (x, y),  # координаты левого верхнего угла
                      (x + width, y + height),  # ширина и высота
                      (255, 0, 0),  # Цвет (B, G, R)
                      3)  # Толщина линии

    # Отображение результата
    cv2.imshow('Frame', frame)
    # Завершение по нажатию Esc
    if cv2.waitKey(1) == 27:
        break