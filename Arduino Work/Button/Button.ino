int ledPin=8;
int buttonPin = 12;
int buttonRead;
int dt = 10;



void setup() {
Serial.begin(9600);
pinMode(ledPin , OUTPUT);
pinMode(buttonPin , INPUT);
}

void loop() {
buttonRead = digitalRead(buttonPin);
Serial.println(buttonRead);
delay(dt);
if (buttonRead== 1){
  digitalWrite(ledPin , LOW);

}
if (buttonRead == 0 ){
  digitalWrite(ledPin , HIGH);
}
}
