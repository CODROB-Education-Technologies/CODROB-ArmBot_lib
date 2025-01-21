#ifndef ARMBOT_h
#define ARMBOT_h

#include "Arduino.h"

// Servo kütüphanelerini dahil edin
// Include the Servo libraries
#if defined(ESP32)
#include <ServoESP32.h>
#elif defined(ESP8266)
#include <Servo.h>
#endif

// Platforma göre pin atamaları
// Pin assignments based on platform
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
// Tone definitions
#define a 440
#define ad 466
#define b 494
#define c 523
#define cd 554
#define d 587
#define dd 622
#define e 659
#define f 698
#define fd 740
#define g 784
#define gd 830
#define a2 880
#define ad2 932
#define b2 988
#define c2 1046
#define cd2 1108
#define d2 1174
#define dd2 1244
#define e2 1318
#define f2 1396
#define fd2 1480
#define g2 1568
#define gd2 1660
#define a3 1760

class ARMBOT
{
public:
  ARMBOT();                                        // Kurucu fonksiyon / Constructor
  void begin();                                    // Başlatma fonksiyonu / Initialization function
  void test();                                     // Test fonksiyonu / Test function
  void axis1Motion(int angle, int acceleration);   // Dönme hareket fonksiyonu / Rotation movement function
  void axis2Motion(int angle, int acceleration);   // Omuz hareket fonksiyonu / Shoulder movement function
  void axis3Motion(int angle, int acceleration);   // Dirsek hareket fonksiyonu / Elbow movement function
  void glipperMotion(int angle, int acceleration); // Kaydırma hareket fonksiyonu / Gripper movement function
  void calBuzzer(int tune, int time);              // Buzzer fonksiyonu / Buzzer function
  void istiklalMarsiCal();                         // İstiklal Marşı fonksiyonu / Turkish National Anthem function

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
