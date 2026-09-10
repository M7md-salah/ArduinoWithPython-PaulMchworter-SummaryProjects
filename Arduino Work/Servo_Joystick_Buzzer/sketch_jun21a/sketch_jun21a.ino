#include <Servo.h>
Servo Xservo;
Servo Yservo;
int xPin = A1;
int yPin = A0;
int sPin = 2;
int Xspin = 10;
int Yspin = 9;
int WVx ;
int WVy ;
int Xval;
int Yval;
int Sval;
int dt = 2;
int buzzPin = 7;


void setup() {
  Xservo.attach(Xspin);
  Yservo.attach(Yspin);
  Serial.begin(9600);
  pinMode(13 , OUTPUT);
  pinMode(xPin , INPUT);
  pinMode(yPin , INPUT);
  pinMode(sPin , INPUT);
  pinMode(Xspin , OUTPUT);
  pinMode(Yspin , OUTPUT);
  pinMode(buzzPin ,  OUTPUT);
  digitalWrite(sPin , HIGH);
}

void loop() {
  Xval = analogRead(xPin);
  Yval = analogRead(yPin);
  WVx = (180./1023.)*Xval;
  WVy = (180./1023.)*Yval;
  Sval = digitalRead(sPin);
  Xservo.write(WVx);
  Yservo.write(WVy);
  delay(dt);
  Serial.print(" X val = ");
  Serial.println(Xval);
  Serial.print("Y val = ");
  Serial.println(Yval);
  Serial.print("switch State is ");
  Serial.println(Sval);
  if (Sval == LOW){
    tone(buzzPin , 1000);
    digitalWrite(13 , HIGH);
    
    
  }else{
      noTone(buzzPin);
      digitalWrite(13, LOW);
    }
  
  delay(2);
}