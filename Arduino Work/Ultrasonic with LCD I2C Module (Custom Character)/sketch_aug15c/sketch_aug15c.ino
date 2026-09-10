#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  
int buzzer = 7;
int trig = 3;
int echo = 2;
int columns;
int speed = 343;
long time;
long distance;
byte face;

byte normalFace[8] = {
  0b00000,
  0b01010,
  0b01010,
  0b00100,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};

byte dangerFace[8] = {
  0b01110,
  0b10101,
  0b11011,
  0b01110,
  0b01010,
  0b00000,
  0b00000,
  0b00000
};

void setup()
{
  lcd.init();                        
  lcd.backlight(); 
  lcd.createChar(1, normalFace);
  lcd.createChar(2, dangerFace);
  Serial.begin(9600);
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(buzzer , OUTPUT);
}

void loop()
{
  digitalWrite(trig , LOW);
  delayMicroseconds(2);
  digitalWrite(trig , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig , LOW);
  
  time = pulseIn (echo, HIGH);
  distance = time * 0.01715;
  columns = map(distance , 0 , 343 , 1 , 17);
  
  if (distance < 150) 
  {
    face = 2;
    digitalWrite(buzzer , HIGH);
  }
  else 
  {
    face = 1;
    digitalWrite(buzzer , LOW);
  }
  
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  
  lcd.setCursor(0,0);
  lcd.write(face);
  
  if ( columns == 2)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<2; i++) {
    lcd.write(face);
    Serial.begin(face);
    }
  }
  else if ( columns == 3)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<3; i++) lcd.write(face);
  }
  else if ( columns == 4)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<4; i++) lcd.write(face);
  }
  else if ( columns == 5)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<5; i++) lcd.write(face);
  }
  else if ( columns == 6)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<6; i++) lcd.write(face);
  }
  else if ( columns == 7)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<7; i++) lcd.write(face);
  }
  else if ( columns == 8)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<8; i++) lcd.write(face);
  }
  else if ( columns == 9)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<9; i++) lcd.write(face);
  }
  else if ( columns == 10)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<10; i++) lcd.write(face);
  }
  else if ( columns == 11)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<11; i++) lcd.write(face);
  }
  else if ( columns == 12)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<12; i++) lcd.write(face);
  }
  else if ( columns == 13)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<13; i++) lcd.write(face);
  }
  else if ( columns == 14)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<14; i++) lcd.write(face);
  }
  else if ( columns == 15)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<15; i++) lcd.write(face);
    lcd.setCursor(14,1);
    lcd.write(face);
  }
  else if ( columns == 16)
  {
    lcd.setCursor(0,0);
    for(int i=0; i<16; i++) lcd.write(face);
    lcd.setCursor(14,1);
    for(int i=0; i<2; i++) lcd.write(face);
  }
  else
  {
  }
  
  delay(100);
}