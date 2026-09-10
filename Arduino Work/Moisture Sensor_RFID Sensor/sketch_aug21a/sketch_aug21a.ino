#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_BUZZER_PIN 2
#define BLUE_LED_PIN 3
#define GREEN_LED_PIN 4
#define MOISTURE_PIN A0  

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2); 

bool systemUnlocked = false; 

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  
  pinMode(LED_BUZZER_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  
  digitalWrite(LED_BUZZER_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);

  lcd.init();                      
  lcd.backlight(); 
  
  lcd.setCursor(0, 0); 
  lcd.print("System Ready...");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (!systemUnlocked) {
    lcd.setCursor(0, 0);
    lcd.print("Scan your card  ");

    if (!mfrc522.PICC_IsNewCardPresent()) {
      return;
    }
    
    if (!mfrc522.PICC_ReadCardSerial()) {
      return;
    }

    digitalWrite(LED_BUZZER_PIN, HIGH); 
    digitalWrite(BLUE_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, HIGH);
    delay(500); 
    digitalWrite(LED_BUZZER_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    
    systemUnlocked = true; 
    lcd.clear(); 
    
    mfrc522.PICC_HaltA(); 
  } 
  else {
    int moistureValue = analogRead(MOISTURE_PIN);
    
    int moisturePercent = map(moistureValue, 0, 1023, 0, 100);
    
    if(moisturePercent < 0) moisturePercent = 0;
    if(moisturePercent > 100) moisturePercent = 100;

    if (moisturePercent < 50) {
      digitalWrite(BLUE_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, LOW);
    } else {
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(BLUE_LED_PIN, LOW);
    }

    lcd.setCursor(0, 0);
    lcd.print("Access Granted! "); 

    lcd.setCursor(0, 1);
    lcd.print("Moisture: ");
    lcd.print(moisturePercent);
    lcd.print("%   "); 

    delay(500); 
  }
}