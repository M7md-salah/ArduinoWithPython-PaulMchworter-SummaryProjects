#include <Servo.h>
Servo Servo1;
int servoPin = 9;
int potPin = A0;

void setup() {
  // put your setup code here, to run once:
Servo1.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
int reading = analogRead(potPin);
int angle = map( reading ,0 , 1023 , 0, 180 );
Servo1.write(angle);
}
