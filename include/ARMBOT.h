#ifndef ARMBOT_h
#define ARMBOT_h

#include "Arduino.h"
#include <ESP32Servo.h> // ESP32Servo kütüphanesi dahil edildi

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

class ARMBOT
{
public:
  ARMBOT();                               // Constructor
  void begin();                           // Pin ve servo başlatma fonksiyonu
  void test();                            // Buzzer testi
  void axis1Motion(int angle);            // Axis 1 hareketi
  void axis2Motion(int angle);            // Axis 2 hareketi
  void axis3Motion(int angle);            // Axis 3 hareketi
  void glipperMotion(int angle);          // Glipper hareketi
  void calBuzzer(int tune, int duration); // Buzzer çalma
  void istiklalMarsiCal();                // İstiklal Marşı çalma

private:
  int _buzzerPin;
  int _axis1Pin;
  int _axis2Pin;
  int _axis3Pin;
  int _glipperPin;

  // Servo nesneleri
  Servo _servoaxis1;
  Servo _servoaxis2;
  Servo _servoaxis3;
  Servo _servoglipper;
};

#endif
