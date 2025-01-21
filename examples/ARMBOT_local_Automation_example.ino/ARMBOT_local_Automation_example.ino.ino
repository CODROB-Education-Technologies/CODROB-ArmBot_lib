#include <ARMBOT.h>

ARMBOT armBot;

void setup() {
  armBot.begin();
  Serial.begin(115200);
}

void loop() {
  // Tüm eksenlerde sırasıyla hareket edecek şekilde bir döngü oluşturuyoruz

   armBot.omuzHareket(90, 50); // Omuz 90 dereceye hareket eder, 50ms ivme ile
    delay(1000); // 1 saniye bekle
    armBot.dirsekHareket(45, 50); // Dirsek 45 dereceye hareket eder, 50ms ivme ile
    delay(1000); // 1 saniye bekle
    armBot.donmeHareket(180, 50); // Dönme 180 dereceye hareket eder, 50ms ivme ile
    delay(1000); // 1 saniye bekle
    armBot.kaydirmaHareket(0, 50); // Kaydırma 0 dereceye hareket eder, 50ms ivme ile
    delay(1000); // 1 saniye bekle

}
