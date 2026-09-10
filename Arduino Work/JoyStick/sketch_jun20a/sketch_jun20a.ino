int xPin = A0;
int yPin = A1;
int sPin = 2;
int Xval;
int Yval;
int Sval;
int dt = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(13 , OUTPUT);
  pinMode(xPin , INPUT);
  pinMode(yPin , INPUT);
  pinMode(sPin , INPUT);
  digitalWrite(sPin , HIGH);
}

void loop() {
  Xval = analogRead(xPin);
  Yval = analogRead(yPin);
  Sval = analogRead(sPin);
  delay(dt);
  digitalWrite( 13 , HIGH);
  Serial.print(" X val = ");
  Serial.println(Xval);
  Serial.print("Y val = ");
  Serial.println(Yval);
  Serial.print("switch State is ");
  Serial.println(Sval);
}
