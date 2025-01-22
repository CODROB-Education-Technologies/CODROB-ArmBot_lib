#include "ARMBOT.h"

// ARMbot'u başlat
void ARMBOT::begin()
{
  // Servo motorları ilgili pinlere bağla
  if (!_axis1Servo.attach(_axis1Pin))
  {
    Serial.println("Axis 1 Servo attach failed!");
  }
  if (!_axis2Servo.attach(_axis2Pin))
  {
    Serial.println("Axis 2 Servo attach failed!");
  }
  if (!_axis3Servo.attach(_axis3Pin))
  {
    Serial.println("Axis 3 Servo attach failed!");
  }
  if (!_gripperServo.attach(_gripperPin))
  {
    Serial.println("Gripper Servo attach failed!");
  }

  // Motorları başlangıç pozisyonlarına getir
  _axis1Servo.write(_axis1LastPos);
  _axis2Servo.write(_axis2LastPos);
  _axis3Servo.write(_axis3LastPos);
  _gripperServo.write(_gripperLastPos);
}

// Hareketi yavaşça yapmak için açı geçiş fonksiyonu
void ARMBOT::moveToAngle(int &lastPos, int angle, int speed)
{
  int step = (angle > lastPos) ? 1 : -1; // Hareket yönü
  while (lastPos != angle)
  {
    lastPos += step; // Pozisyonu adım adım artır veya azalt

    // Doğru servo motorunu kontrol et
    if (&lastPos == &_axis1LastPos)
      _axis1Servo.write(lastPos);
    if (&lastPos == &_axis2LastPos)
      _axis2Servo.write(lastPos);
    if (&lastPos == &_axis3LastPos)
      _axis3Servo.write(lastPos);
    if (&lastPos == &_gripperLastPos)
      _gripperServo.write(lastPos);

    delay(speed); // Hızı belirleyen gecikme

    // Hedef pozisyona ulaşıldığında döngüden çık
    if ((step > 0 && lastPos >= angle) || (step < 0 && lastPos <= angle))
    {
      lastPos = angle; // Pozisyonu hedef açıya sabitle
      break;
    }
  }
}

// Hareket fonksiyonları
void ARMBOT::axis1Motion(int angle, int speed)
{
  moveToAngle(_axis1LastPos, angle, speed);
}

void ARMBOT::axis2Motion(int angle, int speed)
{
  moveToAngle(_axis2LastPos, angle, speed);
}

void ARMBOT::axis3Motion(int angle, int speed)
{
  moveToAngle(_axis3LastPos, angle, speed);
}

void ARMBOT::gripperMotion(int angle, int speed)
{
  moveToAngle(_gripperLastPos, angle, speed);
}

// Buzzer fonksiyonu
void ARMBOT::buzzerPlay(int frequency, int duration)
{
  analogWrite(_buzzerPin, frequency);
  delay(duration); // Gecikme
  analogWrite(_buzzerPin, 0);
}

void ARMBOT::istiklalMarsiCal()
{
  // İstiklal Marşı'nın melodisini buzzer ile çalıyoruz
  // Korkma, sönmez bu şafaklarda yüzen al sancak

  tone(_buzzerPin, 262, 400); // C4
  delay(400);
  tone(_buzzerPin, 330, 400); // E4
  delay(400);
  tone(_buzzerPin, 392, 400); // G4
  delay(400);
  tone(_buzzerPin, 349, 400); // F4
  delay(400);
  tone(_buzzerPin, 330, 600); // E4
  delay(600);

  // Sönmeden yurdumun üstünde tüten en son ocak

  tone(_buzzerPin, 349, 400); // F4
  delay(400);
  tone(_buzzerPin, 330, 400); // E4
  delay(400);
  tone(_buzzerPin, 294, 400); // D4
  delay(400);
  tone(_buzzerPin, 262, 600); // C4
  delay(600);

  // O benim milletimin yıldızıdır, parlayacak

  tone(_buzzerPin, 330, 400); // E4
  delay(400);
  tone(_buzzerPin, 349, 400); // F4
  delay(400);
  tone(_buzzerPin, 392, 400); // G4
  delay(400);
  tone(_buzzerPin, 330, 600); // E4
  delay(600);

  // O benimdir, o benim milletimindir ancak

  tone(_buzzerPin, 294, 400); // D4
  delay(400);
  tone(_buzzerPin, 262, 400); // C4
  delay(400);
  tone(_buzzerPin, 294, 600); // D4
  delay(600);

  noTone(_buzzerPin); // Buzzer sesini durdur
}
