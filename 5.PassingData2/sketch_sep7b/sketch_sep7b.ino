String myCmd;
int blue = 4;
int green = 3;
int yellow = 2;

void setup() {

Serial.begin(9600);

pinMode(blue , OUTPUT);
pinMode(green , OUTPUT);
pinMode(yellow , OUTPUT);

}

void loop() {
while (Serial.available() == 0){

}
myCmd = Serial.readStringUntil('\r');

myCmd.trim();
myCmd.toUpperCase();
Serial.println(myCmd);

if (myCmd == "BLUE"){
  digitalWrite(blue , HIGH);
  digitalWrite(green , LOW);
  digitalWrite(yellow , LOW);
}

if (myCmd == "GREEN"){
  digitalWrite(green , HIGH);
  digitalWrite(blue , LOW);
  digitalWrite(yellow , LOW);
}

if (myCmd == "YELLOW"){
  digitalWrite(yellow , HIGH);
  digitalWrite(blue , LOW);
  digitalWrite(green , LOW);
}

if (myCmd == "TRAFFIC"){
 while (Serial.available() == 0) {

      digitalWrite(green, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(blue, LOW);
      delay(150); 
      
      digitalWrite(green, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(blue, LOW);
      delay(150);
      
      digitalWrite(green, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(blue, HIGH);
      delay(150); 
    }
  }
}


