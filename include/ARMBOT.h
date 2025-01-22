#ifndef ARMBOT_H
#define ARMBOT_H

#include <Arduino.h>

// Platforma göre gerekli kütüphaneyi seç
#if defined(ESP32)
#include <ESP32Servo.h>
#elif defined(ESP8266)
#include <Servo.h>
#endif

class ARMBOT
{
public:
  void begin();
  void axis1Motion(int angle, int speed);
  void axis2Motion(int angle, int speed);
  void axis3Motion(int angle, int speed);
  void gripperMotion(int angle, int speed);
  void buzzerPlay(int frequency, int duration);
  void istiklalMarsiCal();

private:
  void moveToAngle(int &lastPos, int angle, int speed);

  // Servo nesneleri
#if defined(ESP32) || defined(ESP8266)
  Servo _axis1Servo;
  Servo _axis2Servo;
  Servo _axis3Servo;
  Servo _gripperServo;
#endif

  // Son pozisyon değişkenleri
  int _axis1LastPos = 90;
  int _axis2LastPos = 90;
  int _axis3LastPos = 50;
  int _gripperLastPos = 60;

  // Platforma göre pin tanımlamaları
#if defined(ESP32)
  const int _axis1Pin = 25;
  const int _axis2Pin = 26;
  const int _axis3Pin = 27;
  const int _gripperPin = 32;
  const int _buzzerPin = 33;

#elif defined(ESP8266)
  const int _axis1Pin = 5;
  const int _axis2Pin = 4;
  const int _axis3Pin = 12;
  const int _gripperPin = 13;
  const int _buzzerPin = 14;
#endif
};

#endif
