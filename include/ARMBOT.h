#ifndef ARMBOT_H
#define ARMBOT_H

#include <Arduino.h>

// Select appropriate library based on the platform / Platforma göre kütüphaneyi seç
#if defined(ESP32)
#include <ESP32Servo.h>
#elif defined(ESP8266)
#include <Servo.h>
#endif

class ARMBOT
{
public:
  void begin();                                 // Initialize ARMBOT / ARMBOT'u başlat
  void axis1Motion(int angle, int speed);       // Move Axis 1 / Eksen 1'i hareket ettir
  void axis2Motion(int angle, int speed);       // Move Axis 2 / Eksen 2'yi hareket ettir
  void axis3Motion(int angle, int speed);       // Move Axis 3 / Eksen 3'ü hareket ettir
  void gripperMotion(int angle, int speed);     // Move Gripper / Gripper'ı hareket ettir
  void buzzerPlay(int frequency, int duration); // Play a tone / Ses çıkar
  void istiklalMarsiCal();                      // Play the National Anthem melody / İstiklal Marşı'nı çal

private:
  void moveToAngle(int &lastPos, int angle, int speed); // Smooth movement / Yumuşak hareket

  // Servo objects for the axes and gripper / Servo motor nesneleri
  Servo _axis1Servo, _axis2Servo, _axis3Servo, _gripperServo;

  // Last position variables for each axis / Her eksen için son pozisyon değişkenleri
  int _axis1LastPos = 90;
  int _axis2LastPos = 90;
  int _axis3LastPos = 50;
  int _gripperLastPos = 60;

  // Platform-specific pin assignments / Platforma özgü pin tanımlamaları
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
