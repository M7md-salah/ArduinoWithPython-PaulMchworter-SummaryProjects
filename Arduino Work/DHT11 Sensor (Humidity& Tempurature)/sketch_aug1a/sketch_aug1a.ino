#include <DHT.h> // تعديل اسم المكتبة

#define Type DHT11
int sensor = 2;

DHT HT(sensor, Type); // تعديل اسم الكلاس لـ DHT بدلاً من DHT11

float hum;
float Tc;
float Tf;
int dt = 500;

void setup() {
  Serial.begin(9600);
  HT.begin(); // تعديل حرف الـ B ليكون b (small)
  delay(dt);
}

void loop() {
  hum = HT.readHumidity();
  Tc = HT.readTemperature();
  Tf = HT.readTemperature(true);

  // أوامر الطباعة عشان تقدر تشوف القرايات على الـ Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %  |  ");
  
  Serial.print("Temperature: ");
  Serial.print(Tc);
  Serial.println(" C");

  delay(1000); // يفضل تخلي التأخير ثانيتين على الأقل لأن سينسور DHT11 بطيء في القراءة
}
