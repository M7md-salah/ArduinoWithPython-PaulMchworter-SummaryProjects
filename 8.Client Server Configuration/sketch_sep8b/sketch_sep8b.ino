#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

float tempF;
float humidity;
String cmd;

DHT TH(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  TH.begin();
  delay(2000); 
}

void loop() {
  while (Serial.available() == 0) {
  }
  
  cmd = Serial.readStringUntil('\r');
  cmd.trim();

  if (cmd == "temp") {
    tempF = TH.readTemperature(true); 
    Serial.print("temp,");
    Serial.println(tempF);
  }
  else if (cmd == "hum") {
    humidity = TH.readHumidity(); 
    Serial.print("hum,");
    Serial.println(humidity);
  }
}