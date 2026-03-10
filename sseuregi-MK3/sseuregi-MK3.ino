#include <Servo.h>

Servo servo;
char data;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
  servo.write(90); // 기본 위치
}

void loop() {

  if (Serial.available() > 0) {

    data = Serial.read();

    if(data == 'P'){      // plastic
      servo.write(30);
      delay(2000);
    }

    else if(data == 'C'){ // can
      servo.write(90);
      delay(2000);
    }

    else if(data == 'G'){ // general
      servo.write(150);
      delay(2000);
    }

    servo.write(90); // 중앙 복귀
  }
}