int LatchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt = 500;
byte LEDs = 0b01010101;
byte LED2s= 0b10101010;
void setup() {
  // put your de here, to run once:
Serial.begin(9600);
pinMode(LatchPin , OUTPUT);
pinMode(dataPin , OUTPUT);
pinMode(clockPin , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LatchPin, LOW);
shiftOut(dataPin , clockPin , LSBFIRST, LEDs);
digitalWrite(LatchPin , HIGH);
delay(dt);
digitalWrite(LatchPin, LOW);
shiftOut(dataPin , clockPin , LSBFIRST, LED2s);
digitalWrite(LatchPin , HIGH);
delay(dt);
}
