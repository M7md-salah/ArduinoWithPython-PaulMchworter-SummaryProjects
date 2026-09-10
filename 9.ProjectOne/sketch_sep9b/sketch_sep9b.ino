#include <Servo.h>
Servo myservo;
int servoPin = 2;

int led1 = 7;
int led2 = 8;
int dt = 15; 
bool isGateOpen = false;

int potPin = A0; 
float simulatedDistance;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  myservo.write(0); 

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
}

void loop() {
  int rawValue = analogRead(potPin);
  simulatedDistance = map(rawValue, 0, 1023, 0, 300);
  
  Serial.print("dist,");
  Serial.println(simulatedDistance);

  
  if (simulatedDistance < 150) {
    if (isGateOpen == false) {
      digitalWrite(led1, HIGH); 
      digitalWrite(led2, LOW);  
      
      for(int angle = 0; angle <= 90; angle++) {
        myservo.write(angle);
        delay(dt);
      }
      isGateOpen = true; 
    }
  } 
  
  else {
    if (isGateOpen == true) {
      
      delay(1000); 
      
      digitalWrite(led1, LOW);  
      digitalWrite(led2, HIGH); 
      
      for(int angle = 90; angle >= 0; angle--) {
        myservo.write(angle);
        delay(dt);
      }
      isGateOpen = false; 
    }
  }

  delay(50); 
}