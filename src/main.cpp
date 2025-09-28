#include <ESP32Servo.h>

Servo servo1, servo2, servo3, servo4;
const int servoPin1 = 13, servoPin2 = 12, servoPin3 = 14, servoPin4 = 27;
int angle = 0;        // Переменная для хранения текущего угла
int mode = 1;         // Переменная для режима: 1 = center, 2 = test

void setup() {
    Serial.begin(115200);
    
    // Настройка сервоприводов
    servo1.setPeriodHertz(50);
    servo1.attach(servoPin1, 500, 2500);
    servo2.setPeriodHertz(50);
    servo2.attach(servoPin2, 500, 2500);
    servo3.setPeriodHertz(50);
    servo3.attach(servoPin3, 500, 2500);
    servo4.setPeriodHertz(50);
    servo4.attach(servoPin4, 500, 2500);
    
    Serial.println("Система готова!");
    Serial.println("Используйте: mode = 1 (center) или mode = 2 (test)");
}

void center() {
    Serial.println("ЦЕНТР: Устанавливаю все сервоприводы на 90°");
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
}

void test() {
    Serial.println("ТЕСТ: Запускаю тестовое движение...");
    
    for (angle = 0; angle <= 180; angle += 2) {
        servo1.write(angle);
        servo2.write(angle);
        servo3.write(angle);
        servo4.write(angle);
        delay(20);
    }
    
    for (angle = 180; angle >= 0; angle -= 2) {
        servo1.write(angle);
        servo2.write(angle);
        servo3.write(angle);
        servo4.write(angle);
        delay(20);
    }
}

void loop() {
    // Если mode = 1, то использовать функцию center
    if (mode == 1) {
        center();
        mode = 0; // Чтобы не повторять постоянно
    }
    
    // Если mode = 2, то использовать функцию test  
    if (mode == 2) {
        test();
        mode = 0; // Чтобы не повторять постоянно
    }
    
    // Можно менять режим через монитор порта
    if (Serial.available() > 0) {
        mode = Serial.parseInt();
        Serial.print("Установлен режим: ");
        Serial.println(mode);
    }
}