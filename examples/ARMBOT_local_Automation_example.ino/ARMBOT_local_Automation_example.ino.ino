#include <ESP32Servo.h> // ESP32Servo kütüphanesini dahil ediyoruz
                        // Including the ESP32Servo library

// Servo motor nesneleri
Servo OmuzServo;     // Omuz hareketi için servo motor
Servo DirsekServo;   // Dirsek hareketi için servo motor
Servo DonmeServo;    // Döner eksen için servo motor
Servo KaydirmaServo; // Kaydırma hareketi için servo motor

// Pin Tanımlamaları
const int omuzServoPin = 26;     // Omuz servo motoru için pin
const int dirsekServoPin = 27;   // Dirsek servo motoru için pin
const int donmeServoPin = 25;    // Döner servo motoru için pin
const int kaydirmaServoPin = 32; // Kaydırma servo motoru için pin

void setup()
{
  // Seri haberleşmeyi başlat
  Serial.begin(115200);
  Serial.println("Lokal ArmBot Otomasyonu Başlatılıyor...");

  // Servo motorları başlat
  OmuzServo.attach(omuzServoPin);
  DirsekServo.attach(dirsekServoPin);
  DonmeServo.attach(donmeServoPin);
  KaydirmaServo.attach(kaydirmaServoPin);

  // Servo motorları başlangıç pozisyonuna ayarla
  OmuzServo.write(90);     // Orta pozisyon
  DirsekServo.write(90);   // Orta pozisyon
  DonmeServo.write(90);    // Orta pozisyon
  KaydirmaServo.write(90); // Orta pozisyon

  Serial.println("Servo motorlar başlangıç pozisyonlarına ayarlandı.");
}

void loop()
{
  // **Omuz Hareketi**
  Serial.println("Omuz 90 dereceye hareket ediyor...");
  OmuzServo.write(90); // Omuz 90 dereceye hareket eder
  delay(1000);         // 1 saniye bekle

  // **Dirsek Hareketi**
  Serial.println("Dirsek 45 dereceye hareket ediyor...");
  DirsekServo.write(45); // Dirsek 45 dereceye hareket eder
  delay(1000);           // 1 saniye bekle

  // **Dönme Hareketi**
  Serial.println("Döner eksen 180 dereceye hareket ediyor...");
  DonmeServo.write(180); // Döner eksen 180 dereceye hareket eder
  delay(1000);           // 1 saniye bekle

  // **Kaydırma Hareketi**
  Serial.println("Kaydırma ekseni 0 dereceye hareket ediyor...");
  KaydirmaServo.write(0); // Kaydırma ekseni 0 dereceye hareket eder
  delay(1000);            // 1 saniye bekle

  // Döngü tekrar eder
  Serial.println("Hareketler tamamlandı, döngü tekrar başlıyor...");
}
