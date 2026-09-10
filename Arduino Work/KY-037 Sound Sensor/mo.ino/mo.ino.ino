int soundPin = A0; 
int soundValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  soundValue = analogRead(soundPin);
  
  Serial.println(soundValue);
  
  delay(20); 
}