#include <Stepper.h>
int SPR = 2048;
int buttonpin = 2;
int motorD = 1;
int buttonVal;
int buttonValold=1;
Stepper Mystepper(SPR ,8,9,10,11);
int motSpeed = 10;
int dt = 250;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Mystepper.setSpeed(motSpeed);
pinMode(buttonpin , INPUT);
digitalWrite(buttonpin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonVal = digitalRead(buttonpin);
if (buttonValold == 1 && buttonVal == 0){
  motorD = motorD*(-1);
}
Mystepper.step(motorD*1);
}
