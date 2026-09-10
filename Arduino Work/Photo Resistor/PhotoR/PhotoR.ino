int lightPin = A0;
int buzzPin = 8;
int lightVal;
int delayT;

void setup() {
pinMode(A0 , INPUT);
pinMode(buzzPin , OUTPUT);
Serial.begin(9600);
pinMode(13 , OUTPUT);
}

void loop() {
lightVal = analogRead(lightPin);
delayT= (9./550.)*lightVal-(9.*200./550.)+1.;
Serial.println(delayT);
digitalWrite(buzzPin , HIGH);
delay(delayT);
digitalWrite(buzzPin , LOW);
delay(delayT);

digitalWrite(13 , HIGH);
delay(100);
digitalWrite(13 , LOW);
delay(100);
}
