#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// إعداد الشاشة (عنوان 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// تعريف ترددات النوتات الموسيقية
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784

// النغمات بالترتيب لأغنية Happy Birthday
int melody[] = {
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_B4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5,
  NOTE_G4, NOTE_G4, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_F5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_C5
};

// سرعة كل نوتة موسيقية
int noteDurations[] = {
  8, 8, 4, 4, 4, 2,
  8, 8, 4, 4, 4, 2,
  8, 8, 4, 4, 4, 4, 2,
  8, 8, 4, 4, 4, 2
};

// تعريف أطراف التوصيل
const int buzzer1Pin = 8; // البازر الأول
const int buzzer2Pin = 7; // البازر التاني الجديد
const int led1 = 9;
const int led2 = 10;
const int led3 = 11;

void setup() {
  lcd.init();
  
  // تحديد الأطراف كمُخرجات
  pinMode(buzzer1Pin, OUTPUT);
  pinMode(buzzer2Pin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  // تشغيل الاحتفال 5 مرات 
  for(int cycle = 0; cycle < 5; cycle++) {
    
    // 1. حركة الرعشة في إضاءة الشاشة
    for(int j=0; j<3; j++) {
      lcd.backlight();
      delay(200);
      lcd.noBacklight();
      delay(200);
    }
    lcd.backlight(); // نثبت الإضاءة
    
    // 2. كتابة التهنئة
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Happy Birthday");
    lcd.setCursor(4, 1);
    lcd.print("To You!!!");
    
    // 3. تشغيل المزيكا التبادلية واللمبات
    for (int thisNote = 0; thisNote < 25; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      
      // تحديد أي بازر هيعزف النوتة دي (تبديل بناءً على رقم النوتة زوجي ولا فردي)
      int activeBuzzer;
      if (thisNote % 2 == 0) {
        activeBuzzer = buzzer1Pin;
      } else {
        activeBuzzer = buzzer2Pin;
      }
      
      // عزف النوتة على البازر اللي عليه الدور
      tone(activeBuzzer, melody[thisNote], noteDuration);
      
      // حركة اللمبات
      if(thisNote % 3 == 0) {
        digitalWrite(led1, HIGH); digitalWrite(led2, LOW); digitalWrite(led3, LOW);
      } else if (thisNote % 3 == 1) {
        digitalWrite(led1, LOW); digitalWrite(led2, HIGH); digitalWrite(led3, LOW);
      } else {
        digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, HIGH);
      }
      
      // استراحة بسيطة بين كل نوتة والتانية
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      
      // وقف الصوت عن البازر اللي كان شغال
      noTone(activeBuzzer); 
    }
    
    // نطفي اللمبات بعد ما الأغنية تخلص
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    
    delay(1000); // استراحة قبل الإعادة
  }
  
  // النهاية
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Party is Over!");
}

void loop() {
  // فاضية لأن الكود بيشتغل 5 مرات في الـ setup
}