#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// إعداد الشاشة: العنوان غالباً 0x27، والشاشة 16 عمود و 2 صف
LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup() {
  lcd.init();                      // تشغيل الشاشة
  lcd.backlight();                 // تشغيل الإضاءة الخلفية
  
  lcd.setCursor(1, 0);             // الوقوف في أول عمود، وأول صف
  lcd.print("Hello, World!");      // طباعة النص
  
  lcd.setCursor(0, 1);             // الوقوف في أول عمود، وتاني صف
  lcd.print("I2C is working!");
}

void loop() {
  // مش محتاجين نكتب حاجة هنا دلوقتي
}