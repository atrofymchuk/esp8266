#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN D1
#define SS_PIN D2
MFRC522 mfrc522(SS_PIN, RST_PIN);
//---------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println(F("Ready"));
}
//---------------------------------------------------------------------
void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String uid_;
    uid_ += String(mfrc522.uid.uidByte[1]) + String(mfrc522.uid.uidByte[2]) + String( mfrc522.uid.uidByte[3]) + String( mfrc522.uid.uidByte[4]);
    Serial.print(F("Card UID: ")); Serial.println(uid_.toInt());
    delay(500);
  }
}
