#include <ARMBOT.h>
ARMBOT armbot;

void setup()
{
  armbot.begin(); // ARMBOT'u başlat
                  // Buzzer çalma örneği
  armbot.buzzerPlay(500, 300);
  delay(1000);
}

void loop()
{
  // Axis 1 hareketleri
  armbot.buzzerPlay(1000, 50);
  delay(100);

  armbot.axis1Motion(0, 20); // Axis 1 sıfır açısına hareket
  delay(1000);
  armbot.axis1Motion(180, 20); // Axis 1 maksimum açıya hareket
  delay(1000);
  armbot.axis1Motion(90, 20); // Axis 1 orta noktaya hareket
  delay(1000);

  // Axis 2 hareketleri
  armbot.buzzerPlay(1000, 50);
  delay(100);
  armbot.buzzerPlay(1000, 50);
  delay(100);

  armbot.axis2Motion(0, 20);
  delay(1000);
  armbot.axis2Motion(180, 20);
  delay(1000);
  armbot.axis2Motion(90, 20);
  delay(1000);

  // Axis 3 hareketleri
  armbot.buzzerPlay(1000, 50);
  delay(100);
  armbot.buzzerPlay(1000, 50);
  delay(100);
  armbot.buzzerPlay(1000, 50);
  delay(100);

  armbot.axis3Motion(20, 20);
  delay(1000);
  armbot.axis3Motion(180, 20);
  delay(1000);
  armbot.axis3Motion(50, 20);
  delay(1000);

  // Gripper hareketleri
  armbot.buzzerPlay(1000, 50);
  delay(100);
  armbot.buzzerPlay(1000, 50);
  delay(100);
  armbot.buzzerPlay(1000, 50);
  delay(100);
  armbot.buzzerPlay(1000, 50);
  delay(100);

  armbot.gripperMotion(0, 20);
  delay(1000);
  armbot.gripperMotion(110, 20);
  delay(1000);
  armbot.gripperMotion(60, 20);
  delay(1000);
}
