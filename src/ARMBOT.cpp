#include "include/ARMBOT.h"

// ARMBOT sınıfının kurucu fonksiyonu
// Constructor function of ARMBOT class
ARMBOT::ARMBOT()
{
  // Kurucu fonksiyonun işlemleri buraya yazılır, eğer gerekliyse.
  // Initialization tasks, if needed, are written here.
}

void ARMBOT::begin()
{
  // Pin atamalarını burada yapıyoruz
  // Assigning pins for the robot
  _buzzerPin = buzzer_pin;
  _axis1Pin = axis1_pin;
  _axis2Pin = axis2_pin;
  _axis3Pin = axis3_pin;
  _glipperPin = glipper_pin;

  // Pin modlarını ayarla
  // Setting pin modes
  pinMode(_buzzerPin, OUTPUT);
  pinMode(_axis1Pin, OUTPUT);
  pinMode(_axis2Pin, OUTPUT);
  pinMode(_axis3Pin, OUTPUT);
  pinMode(_glipperPin, OUTPUT);

  // Servo motorları pinlere ata
  // Attach servo motors to pins
#ifdef ESP32
  _servoaxis1.attach(_axis1Pin);
  _servoaxis2.attach(_axis2Pin);
  _servoaxis3.attach(_axis3Pin);
  _servoglipper.attach(_glipperPin);
#elif ESP8266
  _servoaxis1.attach(_axis1Pin);
  _servoaxis2.attach(_axis2Pin);
  _servoaxis3.attach(_axis3Pin);
  _servoglipper.attach(_glipperPin);
#endif
}

void ARMBOT::test()
{
  // Kütüphanenin doğru çalıştığını test etmek için basit bir test kodu
  // Simple test function to verify the library is working correctly
#ifdef ESP32
  tone(_buzzerPin, 1000, 500); // ESP32 için buzzer ses çalma
  // Play a tone with the buzzer for ESP32
#else
  digitalWrite(_buzzerPin, HIGH); // ESP8266 için buzzer aç
  delay(500);
  digitalWrite(_buzzerPin, LOW); // ESP8266 için buzzer kapat
#endif
}

void ARMBOT::axis1Motion(int angle, int acceleration)
{
  // Dönme hareketini sağlayan fonksiyon
  // Function to control rotation movement
#ifdef ESP32
  _servoaxis1.write(angle); // ESP32 servo hareketi
#elif ESP8266
  _servoaxis1.write(angle); // ESP8266 servo hareketi
#endif
}

void ARMBOT::axis2Motion(int angle, int acceleration)
{
  // Omuzun hareketini sağlayan fonksiyon
  // Function to control shoulder movement
#ifdef ESP32
  _servoaxis2.write(angle); // ESP32 servo hareketi
#elif ESP8266
  _servoaxis2.write(angle); // ESP8266 servo hareketi
#endif
}

void ARMBOT::axis3Motion(int angle, int acceleration)
{
  // Dirseğin hareketini sağlayan fonksiyon
  // Function to control elbow movement
#ifdef ESP32
  _servoaxis3.write(angle); // ESP32 servo hareketi
#elif ESP8266
  _servoaxis3.write(angle); // ESP8266 servo hareketi
#endif
}

void ARMBOT::glipperMotion(int angle, int acceleration)
{
  // Kaydırma hareketini sağlayan fonksiyon
  // Function to control gripper movement
#ifdef ESP32
  _servoglipper.write(angle); // ESP32 servo hareketi
#elif ESP8266
  _servoglipper.write(angle); // ESP8266 servo hareketi
#endif
}

void ARMBOT::calBuzzer(int tune, int sure)
{
  // Buzzer üzerinde belirli bir nota çalmak için fonksiyon
  // Function to play a tone on the buzzer
#ifdef ESP32
  tone(_buzzerPin, tune, sure); // ESP32 için tone fonksiyonu
#else
  tone(_buzzerPin, tune);
  delay(sure);
  noTone(_buzzerPin);
#endif
}

void ARMBOT::istiklalMarsiCal()
{
  // İstiklal Marşı'nı çalan fonksiyon
  // Function to play the Turkish National Anthem
  // Korkma Sönmez Bu Şafak
  tone(_buzzerPin, c);
  delay(800);
  tone(_buzzerPin, f);
  delay(800);
  tone(_buzzerPin, g);
  delay(800);
  tone(_buzzerPin, gd);
  delay(800);
  tone(_buzzerPin, e);
  delay(400);
  tone(_buzzerPin, g);
  delay(200);
  tone(_buzzerPin, f);
  delay(1600);
  noTone(_buzzerPin);
  delay(300);
  // Larda Yüzden Al Sancak
  tone(_buzzerPin, f);
  delay(800);
  tone(_buzzerPin, ad2);
  delay(800);
  tone(_buzzerPin, c2);
  delay(800);
  tone(_buzzerPin, cd2);
  delay(800);
  tone(_buzzerPin, a2);
  delay(400);
  tone(_buzzerPin, c2);
  delay(200);
  tone(_buzzerPin, ad2);
  delay(1600);
  // Sönmeden Yurdumun Üstünde Tüten En Son Ocak O Be
  tone(_buzzerPin, c2);
  delay(200);
  tone(_buzzerPin, ad2);
  delay(200);
  tone(_buzzerPin, c2);
  delay(200);
  tone(_buzzerPin, g);
  delay(400);
  noTone(_buzzerPin);
  delay(100);
  tone(_buzzerPin, g);
  delay(400);
  tone(_buzzerPin, ad);
  delay(200);
  tone(_buzzerPin, gd);
  delay(400);
  tone(_buzzerPin, e);
  delay(200);
  tone(_buzzerPin, f);
  delay(400);
  tone(_buzzerPin, g);
  delay(200);
  tone(_buzzerPin, gd);
  delay(400);
  tone(_buzzerPin, ad);
  delay(200);
  tone(_buzzerPin, c2);
  delay(400);
  tone(_buzzerPin, cd2);
  delay(200);
  tone(_buzzerPin, dd2);
  delay(400);
  tone(_buzzerPin, f2);
  delay(200);
  tone(_buzzerPin, dd2);
  delay(400);
  // Nim Milletimin
  tone(_buzzerPin, dd);
  delay(200);
  tone(_buzzerPin, d);
  delay(200);
  tone(_buzzerPin, dd);
  delay(200);
  tone(_buzzerPin, c2);
  delay(800);
  tone(_buzzerPin, ad);
  delay(800);
  tone(_buzzerPin, gd);
  delay(1600);
  // Yıldızıdır Parlayacak O benim
  tone(_buzzerPin, c);
  delay(200);
  tone(_buzzerPin, b);
  delay(200);
  tone(_buzzerPin, c);
  delay(200);
  tone(_buzzerPin, g);
  delay(800);
  tone(_buzzerPin, c);
  delay(800);
  tone(_buzzerPin, c2);
  delay(800);
  tone(_buzzerPin, ad);
  delay(200);
  tone(_buzzerPin, gd);
  delay(200);
  tone(_buzzerPin, g);
  delay(400);
  tone(_buzzerPin, gd);
  delay(200);
  tone(_buzzerPin, f);
  delay(800);
  // Dir O Benim Milletimindir Ancak
  tone(_buzzerPin, f2);
  delay(800);
  tone(_buzzerPin, dd2);
  delay(200);
  tone(_buzzerPin, cd2);
  delay(400);
  tone(_buzzerPin, c2);
  delay(200);
  tone(_buzzerPin, ad);
  delay(400);
  tone(_buzzerPin, gd);
  delay(200);
  tone(_buzzerPin, g);
  delay(400);
  tone(_buzzerPin, f);
  delay(200);
  tone(_buzzerPin, c2);
  delay(400);
  tone(_buzzerPin, c);
  delay(800);
  tone(_buzzerPin, f);
  delay(1600);
  // İKİNCİ KITA
  // Çatma Kurban Olayım
  tone(_buzzerPin, c);
  delay(800);
  tone(_buzzerPin, f);
  delay(800);
  tone(_buzzerPin, g);
  delay(800);
  tone(_buzzerPin, gd);
  delay(800);
  tone(_buzzerPin, e);
  delay(400);
  tone(_buzzerPin, g);
  delay(200);
  tone(_buzzerPin, f);
  delay(1600);
  noTone(_buzzerPin);
  delay(300);
  // Çehreni Ey Nazlı Hilal
  tone(_buzzerPin, f);
  delay(800);
  tone(_buzzerPin, ad2);
  delay(800);
  tone(_buzzerPin, c2);
  delay(800);
  tone(_buzzerPin, cd2);
  delay(400);
  tone(_buzzerPin, ad2);
  delay(400);
  tone(_buzzerPin, a2);
  delay(400);
  tone(_buzzerPin, c2);
  delay(400);
  tone(_buzzerPin, ad2);
  delay(800);
  // Kahraman Irkıma Bir Gül Ne Bu Şiddet Bu Celal Sana
  tone(_buzzerPin, c2);
  delay(200);
  tone(_buzzerPin, ad2);
  delay(200);
  tone(_buzzerPin, c2);
  delay(200);
  tone(_buzzerPin, g);
  delay(400);
  noTone(_buzzerPin);
  delay(100);
  tone(_buzzerPin, g);
  delay(400);
  tone(_buzzerPin, ad);
  delay(200);
  tone(_buzzerPin, gd);
  delay(400);
  tone(_buzzerPin, e);
  delay(200);
  tone(_buzzerPin, f);
  delay(400);
  tone(_buzzerPin, g);
  delay(200);
  tone(_buzzerPin, gd);
  delay(400);
  tone(_buzzerPin, ad);
  delay(200);
  tone(_buzzerPin, c2);
  delay(400);
  tone(_buzzerPin, cd2);
  delay(200);
  tone(_buzzerPin, dd2);
  delay(400);
  tone(_buzzerPin, f2);
  delay(200);
  tone(_buzzerPin, dd2);
  delay(400);
  // Olmaz Dökülen
  tone(_buzzerPin, dd);
  delay(200);
  tone(_buzzerPin, d);
  delay(200);
  tone(_buzzerPin, dd);
  delay(200);
  tone(_buzzerPin, c2);
  delay(800);
  tone(_buzzerPin, ad);
  delay(800);
  tone(_buzzerPin, gd);
  delay(1600);
  // Kanlarımız Sonra Helal Hakkıdır
  tone(_buzzerPin, c);
  delay(200);
  tone(_buzzerPin, b);
  delay(200);
  tone(_buzzerPin, c);
  delay(200);
  tone(_buzzerPin, g);
  delay(800);
  tone(_buzzerPin, c);
  delay(800);
  tone(_buzzerPin, c2);
  delay(800);
  tone(_buzzerPin, ad);
  delay(200);
  tone(_buzzerPin, gd);
  delay(200);
  tone(_buzzerPin, g);
  delay(400);
  tone(_buzzerPin, gd);
  delay(200);
  tone(_buzzerPin, f);
  delay(800);
  // Hakk'a Tapan Milletimin İstiklal
  tone(_buzzerPin, f2);
  delay(800);
  tone(_buzzerPin, dd2);
  delay(200);
  tone(_buzzerPin, cd2);
  delay(400);
  tone(_buzzerPin, c2);
  delay(200);
  tone(_buzzerPin, ad);
  delay(400);
  tone(_buzzerPin, gd);
  delay(200);
  tone(_buzzerPin, g);
  delay(400);
  tone(_buzzerPin, f);
  delay(200);
  tone(_buzzerPin, c2);
  delay(400);
  tone(_buzzerPin, c);
  delay(800);
  tone(_buzzerPin, f);
  delay(1600);
  noTone(_buzzerPin);
}