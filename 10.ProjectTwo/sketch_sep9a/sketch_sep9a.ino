#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

int soundPin = A0;
bool isUnlocked = false; 

String mySecretPassword = "6317BE1B"; 

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  
  Serial.println("status,locked");
}

void loop() {
  
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    
    String scannedID = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      if (rfid.uid.uidByte[i] < 0x10) {
        scannedID += "0";
      }
      scannedID += String(rfid.uid.uidByte[i], HEX);
    }
    scannedID.toUpperCase(); 

    if (scannedID == mySecretPassword) {
      
      isUnlocked = !isUnlocked; 
      
      if (isUnlocked == true) {
        Serial.println("status,unlocked");
      } else {
        Serial.println("status,locked");
      }
      
    } else {
      Serial.print("status,denied,");
      Serial.println(scannedID); 
    }
    
    rfid.PICC_HaltA(); 
  }

  if (isUnlocked == true) {
    int soundValue = analogRead(soundPin);
    Serial.print("sound,");
    Serial.println(soundValue);
    
    delay(20); 
  } else {
    delay(50);
  }
}