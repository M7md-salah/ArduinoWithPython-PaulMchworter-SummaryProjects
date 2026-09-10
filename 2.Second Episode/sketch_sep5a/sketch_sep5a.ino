
int sensorValue;
int dt = 100;



void setup() {
Serial.begin(9600);
}

void loop() {
int sensorValue = analogRead(A0);
Serial.println(sensorValue);
delay(dt);
}
