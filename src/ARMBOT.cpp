#include "ARMBOT.h"

// Initialize ARMBOT / ARMBOT'u başlat
void ARMBOT::begin()
{
#if defined(ESP32)
  Serial.println("Initializing ARMBOT on ESP32...");
#elif defined(ESP8266)
  Serial.println("Initializing ARMBOT on ESP8266...");
  analogWriteFreq(50); // **ESP8266 için PWM frekansını 50 Hz olarak ayarla**
#else
  Serial.println("Initializing ARMBOT on an unknown platform...");
#endif

  // Servo bağlama fonksiyonu / Function to attach servos
  auto attachServo = [](Servo &servo, int pin, const char *name)
  {
#if defined(ESP32)
    if (!servo.attach(pin, 500, 2500)) // **ESP32 için 1000-2000 µs kullan**
#elif defined(ESP8266)
    if (!servo.attach(pin, 500, 2500)) // **ESP8266 için PWM sinyal genişliği arttırıldı (500-2500 µs)**
#else
    if (!servo.attach(pin)) // **ESP32 için 1000-2000 µs kullan**
#endif
      Serial.println(String(name) + " Servo attach failed!");
  };

  // **Servo motorları bağla / Attach servos**
  attachServo(_axis1Servo, _axis1Pin, "Axis 1");
  attachServo(_axis2Servo, _axis2Pin, "Axis 2");
  attachServo(_axis3Servo, _axis3Pin, "Axis 3");
  attachServo(_gripperServo, _gripperPin, "Gripper");

  // **Servo motorlarını başlangıç pozisyonlarına ayarla / Set initial positions**
  _axis1Servo.write(_axis1LastPos);
  _axis2Servo.write(_axis2LastPos);
  _axis3Servo.write(_axis3LastPos);
  _gripperServo.write(_gripperLastPos);
}

// Smooth movement to target angle / Hedef açıya yumuşak hareket
void ARMBOT::moveToAngle(int &currentAngle, int angle, int speed)
{
  // Eğer açı sınırların dışındaysa, sınırlar içinde tut
  angle = constrain(angle, 0, 180);

  // İlk hareketi mevcut açıdan başlat (ilk başta 0'a gitmesini önlemek için)
  if (currentAngle == -1)
  {
    currentAngle = angle;
  }

  int step = (angle > currentAngle) ? 1 : -1; // Hareket yönünü belirle

  while (currentAngle != angle)
  {
    currentAngle += step;

    if (&currentAngle == &_axis1LastPos)
      _axis1Servo.write(currentAngle);
    if (&currentAngle == &_axis2LastPos)
      _axis2Servo.write(currentAngle);
    if (&currentAngle == &_axis3LastPos)
      _axis3Servo.write(currentAngle);
    if (&currentAngle == &_gripperLastPos)
      _gripperServo.write(currentAngle);

    delay(speed); // Hareket hızını kontrol et

    // Hedef açıya ulaşıldıysa çık
    if ((step > 0 && currentAngle >= angle) || (step < 0 && currentAngle <= angle))
    {
      currentAngle = angle;
      break;
    }
  }
}

// **Eksen kontrol fonksiyonları / Axis control functions**
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
