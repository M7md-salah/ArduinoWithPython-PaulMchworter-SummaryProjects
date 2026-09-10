#include <Servo.h>
int servoPin = 10;
int lightPin = A4;
int lightVal;
int dt = 250;
int angle ; 
Servo myServo;


void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(A4 , INPUT);
  pinMode( 13 , OUTPUT);
  pinMode(servoPin , INPUT);
  

}

void loop() {
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(dt);
  angle = (-16./63.)*lightVal+16.*780./63.;
  myServo.write(angle);
}
