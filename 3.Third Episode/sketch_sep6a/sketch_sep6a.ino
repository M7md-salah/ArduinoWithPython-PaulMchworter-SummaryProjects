#include <DHT.h>

#define Type DHT11
int sensor = 2;
DHT TH(sensor, Type); 

float tempF;
float tempC;
float humidity;

int dt = 700;

void setup() {
  Serial.begin(9600);
  TH.begin();
}

void loop() {
  tempC = TH.readTemperature();
  tempF = TH.readTemperature(true);
  humidity = TH.readHumidity();

Serial.print(tempF);
Serial.print(" , ");
Serial.println(humidity);

delay(dt);
}
