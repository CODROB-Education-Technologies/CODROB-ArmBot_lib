// ARMBOT.h dosyasında, sadece bir kez dahil edilmesini sağlayın
#ifndef ARMBOT_h
#define ARMBOT_h

// Arduino.h dosyasını burada dahil edin
#include "Arduino.h"

// Servo kütüphanelerini dahil edin
#if defined(ESP8266)
#include <Servo.h>
#elif defined(ESP32)
#include <ServoESP32.h>
#endif

// Platforma göre pin atamaları
#ifdef ESP8266
const int buzzer_pin = 14;
const int axis1_pin = 5;
const int axis2_pin = 4;
const int axis3_pin = 12;
const int glipper_pin = 13;
#elif ESP32
const int buzzer_pin = 33;
const int axis1_pin = 25;
const int axis2_pin = 26;
const int axis3_pin = 27;
const int glipper_pin = 32;
#endif

// Ses Tonları Tanımlaması
#define a   440
#define ad  466
#define b   494
#define c   523
#define cd  554
#define d   587
#define dd  622
#define e   659
#define f   698
#define fd  740
#define g   784
#define gd  830
#define a2  880
#define ad2 932
#define b2  988
#define c2  1046
#define cd2 1108
#define d2  1174
#define dd2 1244
#define e2  1318
#define f2  1396
#define fd2 1480
#define g2  1568
#define gd2 1660
#define a3  1760

class ARMBOT
{
public:
  ARMBOT();                              // Kurucu fonksiyon
  void begin();                          // Pin atamalarını yapmak için fonksiyon
  void test();                           // Kütüphanenin çalıştığını test etmek için basit bir fonksiyon
  void axis1Motion(int angle, int acceleration);   // Dönme hareketini sağlayan fonksiyon
  void axis2Motion(int angle, int acceleration);   // Omuzun hareketini sağlayan fonksiyon
  void axis3Motion(int angle, int acceleration); // Dirseğin hareketini sağlayan fonksiyon
  void glipperMotion(int angle, int acceleration); // Kaydırma hareketini sağlayan fonksiyon
  void calBuzzer(int tune, int time);    // Buzzer için not çalma fonksiyonu
  void istiklalMarsiCal();    // Buzzer için istiklal marşı çalma fonksiyonu
private:
  int _buzzerPin;
  int _axis1Pin;
  int _axis2Pin;
  int _axis3Pin;
  int _glipperPin;
#ifdef ESP32
  ServoESP32 _servoaxis1;
  ServoESP32 _servoaxis2;
  ServoESP32 _servoaxis3;
  ServoESP32 _servoglipper;
#elif ESP8266
  Servo _servoaxis1;
  Servo _servoaxis2;
  Servo _servoaxis3;
  Servo _servoglipper;
#endif
};

#endif
