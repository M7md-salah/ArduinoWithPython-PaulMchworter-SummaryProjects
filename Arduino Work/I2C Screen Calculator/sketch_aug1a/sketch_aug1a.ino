#include <Wire.h>
#include <LiquidCrystal_I2C.h>

float num1;
float num2;
float ans;
String op;

LiquidCrystal_I2C lcd(0x27, 16, 2);  

// دالة صغيرة عشان تنظف السيريال من أي Enter قديم
void clearSerialBuffer() {
  while (Serial.available() > 0) {
    Serial.read();
  }
}

void setup() {
  lcd.init();               
  lcd.backlight();                
  Serial.begin(9600);
}

void loop() {
  // --- إدخال الرقم الأول ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("input number1");
  
  while (Serial.available() == 0) {} // الانتظار
  num1 = Serial.parseFloat();
  clearSerialBuffer(); // مسح الـ Enter من الذاكرة

  // --- إدخال الرقم الثاني ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("input number2");
  
  while (Serial.available() == 0) {} // الانتظار
  num2 = Serial.parseFloat();
  clearSerialBuffer(); // مسح الـ Enter من الذاكرة

  // --- إدخال العملية الحسابية ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("input operator");
  lcd.setCursor(0, 1); // تعديل: السطر التاني، العمود الأول
  lcd.print("(+ , - , / , *)");
  
  while (Serial.available() == 0) {} // الانتظار
  op = Serial.readStringUntil('\n'); // قراءة النص لحد ما تدوس Enter
  op.trim(); // تنظيف الـ String من أي مسافات مخفية عشان الـ IF تشتغل صح
  clearSerialBuffer();

  // --- الحسابات ---
  if (op == "+") {
    ans = num1 + num2;
  } 
  else if (op == "-") {
    ans = num1 - num2;
  } 
  else if (op == "*") {
    ans = num1 * num2;
  } 
  else if (op == "/") {
    ans = num1 / num2;
  }

  // --- عرض النتيجة ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(num1);
  lcd.print(op);
  lcd.print(num2);
  
  lcd.setCursor(0, 1); // النتيجة في السطر التاني عشان الشاشة تكفي
  lcd.print("= ");
  lcd.print(ans);

  delay(3000); // استنى 3 ثواني قبل ما تعيد من الأول
  clearSerialBuffer(); // تنظيف أخير قبل الإعادة
}