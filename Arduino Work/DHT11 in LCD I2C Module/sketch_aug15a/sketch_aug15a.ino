#include <DHT.h> // تعديل اسم المكتبة
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// إعداد الشاشة: العنوان غالباً 0x27، والشاشة 16 عمود و 2 صف
LiquidCrystal_I2C lcd(0x27, 16, 2);  
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
  lcd.init();                      // تشغيل الشاشة
  lcd.backlight();                 // تشغيل الإضاءة الخلفية
  
}

void loop() {
  hum = HT.readHumidity();
  Tc = HT.readTemperature();
  Tf = HT.readTemperature(true);

  // أوامر الطباعة عشان تقدر تشوف القرايات على الـ Serial Monitor
  lcd.setCursor(0, 0);             // الوقوف في أول عمود، وأول صف
  lcd.print("Humidity :");      // طباعة النص
  
  lcd.setCursor(11, 0);             // الوقوف في أول عمود، وتاني صف
  lcd.print(hum);
  
  lcd.setCursor(0 , 1);
  lcd.print("Temp C :");
  lcd.setCursor (11 , 1);
  lcd.print(Tc);


  delay(1000); // يفضل تخلي التأخير ثانيتين على الأقل لأن سينسور DHT11 بطيء في القراءة
}