// Подключаем библиотеку для работы с сервоприводами на ESP32
#include <ESP32Servo.h>

// Создаем объекты для четырех сервоприводов
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Определяем пины ESP32, к которым подключены сервоприводы
const int servoPin1 = 13;
const int servoPin2 = 12;
const int servoPin3 = 14;
const int servoPin4 = 27;  // Добавили пин для четвертого сервопривода

int angle = 0;  // Переменная для хранения текущего угла

void setup() {
  // Настраиваем последовательное соединение для вывода информации в монитор порта
  Serial.begin(115200);

  // Привязываем каждый объект сервопривода к своему пину
  servo1.setPeriodHertz(50);
  servo1.attach(servoPin1, 500, 2500);

  servo2.setPeriodHertz(50);
  servo2.attach(servoPin2, 500, 2500);

  servo3.setPeriodHertz(50);
  servo3.attach(servoPin3, 500, 2500);

  servo4.setPeriodHertz(50);  // Настраиваем четвертый сервопривод
  servo4.attach(servoPin4, 500, 2500);

  Serial.println("Тест четырех сервоприводов запущен!");
}

void loop() {
  // Плавно увеличиваем угол от 0 до 180 градусов
  for (angle = 0; angle <= 180; angle += 1) {
    servo1.write(angle);
    servo2.write(angle);
    servo3.write(angle);
    servo4.write(angle);
    delay(5);
  }

  // Плавно уменьшаем угол от 180 до 0 градусов
  for (angle = 180; angle >= 0; angle -= 1) {
    servo1.write(angle);
    servo2.write(angle);
    servo3.write(angle);
    servo4.write(angle);
    delay(5);
  }
}