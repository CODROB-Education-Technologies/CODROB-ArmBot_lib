#include "ARMBOT.h"

// ARMBOT sınıfının kurucu fonksiyonu
ARMBOT::ARMBOT()
{
  // Gerekirse kurucu işlemleri buraya yazılır.
}

void ARMBOT::begin()
{
  _buzzerPin = buzzer_pin;
  _axis1Pin = axis1_pin;
  _axis2Pin = axis2_pin;
  _axis3Pin = axis3_pin;
  _glipperPin = glipper_pin;

  pinMode(_buzzerPin, OUTPUT);
  pinMode(_axis1Pin, OUTPUT);
  pinMode(_axis2Pin, OUTPUT);
  pinMode(_axis3Pin, OUTPUT);
  pinMode(_glipperPin, OUTPUT);

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
#ifdef ESP32
  tone(_buzzerPin, 1000, 500);
#else
  digitalWrite(_buzzerPin, HIGH);
  delay(500);
  digitalWrite(_buzzerPin, LOW);
#endif
}

void ARMBOT::axis1Motion(int angle, int acceleration)
{
#ifdef ESP32
  _servoaxis1.write(angle);
#elif ESP8266
  _servoaxis1.write(angle);
#endif
}

void ARMBOT::axis2Motion(int angle, int acceleration)
{
#ifdef ESP32
  _servoaxis2.write(angle);
#elif ESP8266
  _servoaxis2.write(angle);
#endif
}

void ARMBOT::axis3Motion(int angle, int acceleration)
{
#ifdef ESP32
  _servoaxis3.write(angle);
#elif ESP8266
  _servoaxis3.write(angle);
#endif
}

void ARMBOT::glipperMotion(int angle, int acceleration)
{
#ifdef ESP32
  _servoglipper.write(angle);
#elif ESP8266
  _servoglipper.write(angle);
#endif
}

void ARMBOT::calBuzzer(int tune, int sure)
{
#ifdef ESP32
  tone(_buzzerPin, tune, sure);
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