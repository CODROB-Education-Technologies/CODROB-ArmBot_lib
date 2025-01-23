#include "ARMBOT.h"

// Initialize ARMBOT / ARMBOT'u başlat
void ARMBOT::begin()
{
  // Attach servos and check for success / Servo motorları bağla ve başarılı olup olmadığını kontrol et
  if (!_axis1Servo.attach(_axis1Pin))
    Serial.println("Axis 1 Servo attach failed!");
  if (!_axis2Servo.attach(_axis2Pin))
    Serial.println("Axis 2 Servo attach failed!");
  if (!_axis3Servo.attach(_axis3Pin))
    Serial.println("Axis 3 Servo attach failed!");
  if (!_gripperServo.attach(_gripperPin))
    Serial.println("Gripper Servo attach failed!");

  // Set servos to their initial positions / Servo motorlarını başlangıç pozisyonlarına ayarla
  _axis1Servo.write(_axis1LastPos);
  _axis2Servo.write(_axis2LastPos);
  _axis3Servo.write(_axis3LastPos);
  _gripperServo.write(_gripperLastPos);
}

// Smooth movement to target angle / Hedef açıya yumuşak hareket
void ARMBOT::moveToAngle(int &lastPos, int angle, int speed)
{
  int step = (angle > lastPos) ? 1 : -1; // Determine direction / Hareket yönü belirle
  while (lastPos != angle)
  {
    lastPos += step;
    if (&lastPos == &_axis1LastPos)
      _axis1Servo.write(lastPos);
    if (&lastPos == &_axis2LastPos)
      _axis2Servo.write(lastPos);
    if (&lastPos == &_axis3LastPos)
      _axis3Servo.write(lastPos);
    if (&lastPos == &_gripperLastPos)
      _gripperServo.write(lastPos);

    delay(speed);

    // Exit if target reached / Hedefe ulaşılırsa çık
    if ((step > 0 && lastPos >= angle) || (step < 0 && lastPos <= angle))
    {
      lastPos = angle;
      break;
    }
  }
}

// Axis control functions / Eksen kontrol fonksiyonları
void ARMBOT::axis1Motion(int angle, int speed) { moveToAngle(_axis1LastPos, angle, speed); }
void ARMBOT::axis2Motion(int angle, int speed) { moveToAngle(_axis2LastPos, angle, speed); }
void ARMBOT::axis3Motion(int angle, int speed) { moveToAngle(_axis3LastPos, angle, speed); }
void ARMBOT::gripperMotion(int angle, int speed) { moveToAngle(_gripperLastPos, angle, speed); }

// Play a tone with the buzzer / Buzzer ile ses çıkar
void ARMBOT::buzzerPlay(int frequency, int duration)
{
  analogWrite(_buzzerPin, frequency);
  delay(duration);
  analogWrite(_buzzerPin, 0);
}

// Play the National Anthem / İstiklal Marşı'nı çal
void ARMBOT::istiklalMarsiCal()
{
  buzzerPlay(262, 400);
  delay(400);
  buzzerPlay(330, 400);
  delay(400);
  buzzerPlay(392, 400);
  delay(400);
  buzzerPlay(349, 400);
  delay(400);
  buzzerPlay(330, 600);
  delay(600);
  buzzerPlay(349, 400);
  delay(400);
  buzzerPlay(330, 400);
  delay(400);
  buzzerPlay(294, 400);
  delay(400);
  buzzerPlay(262, 600);
  delay(600);
  buzzerPlay(330, 400);
  delay(400);
  buzzerPlay(349, 400);
  delay(400);
  buzzerPlay(392, 400);
  delay(400);
  buzzerPlay(330, 600);
  delay(600);
  buzzerPlay(294, 400);
  delay(400);
  buzzerPlay(262, 400);
  delay(400);
  buzzerPlay(294, 600);
  delay(600);
}
