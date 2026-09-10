int buttonPin1 = 12;
int buttonPin2 = 11;
int LEDpin = 3;
int buzzpin = 2;
int buttonVal1;
int buttonVal2;
int dt = 250;
int LEDBright = 0 ;

void setup() {
pinMode(buttonPin1 , INPUT);
pinMode(buttonPin2, INPUT);
pinMode(LEDpin , OUTPUT);
pinMode(buzzpin , OUTPUT);
Serial.begin(9600);
}

void loop() {

buttonVal1 = digitalRead(buttonPin1);
buttonVal2 = digitalRead(buttonPin2);
Serial.println("button 1 = ");
Serial.println(buttonVal1);
Serial.println(" , ");
Serial.println("button 2 = ");
Serial.println(buttonVal2);

if (buttonVal1 == 0){
  LEDBright = LEDBright+5;
}
if (buttonVal2 == 0){
  LEDBright = LEDBright - 5;
}
if (LEDBright >255){
  LEDBright = 255;
  digitalWrite(buzzpin , HIGH);
  delay(dt);
  digitalWrite( buzzpin , LOW);
  
}
if(LEDBright < 0){
  LEDBright = 0;
  digitalWrite(buzzpin , HIGH);
  delay(dt);
  digitalWrite( buzzpin , LOW);
  

}
analogWrite(LEDpin , LEDBright);
}
