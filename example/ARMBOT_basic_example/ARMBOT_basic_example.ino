#include <ARMBOT.h> // ARMBOT kütüphanesini projeye dahil ediyoruz
                    // Including the ARMBOT library into the project

ARMBOT armbot; // ARMBOT sınıfından bir nesne oluşturuyoruz
                 // Creating an object of the ARMBOT class

void setup()
{
  armbot.begin(); // ARMBOT nesnesinin başlatma fonksiyonunu çağırıyoruz
                  // Calling the initialization function of the ARMBOT object
}

void loop()
{
  // Tüm eksenlerde sırasıyla hareket edecek şekilde bir döngü oluşturuyoruz
  // Creating a loop for sequential movement on all axes

  armbot.calBuzzer(100, 200);  // Playing a note on the buzzer with frequency 100 for 200 milliseconds
                               // Playing a note on the buzzer with frequency 100 for 200 milliseconds
  delay(1000);  // 1 saniye bekle
                // Wait for 1 second

  armbot.axis1Motion(180, 50); // Dönme 180 dereceye hareket eder, 50ms acceleration ile
                               // Rotating to 180 degrees with an acceleration of 50ms
  delay(1000);                 // 1 saniye bekle
                               // Wait for 1 second

  armbot.axis2Motion(90, 50);  // Omuz 90 dereceye hareket eder, 50ms acceleration ile
                               // Moving the shoulder to 90 degrees with an acceleration of 50ms
  delay(1000);                 // 1 saniye bekle
                               // Wait for 1 second
                               
  armbot.axis3Motion(45, 50);  // Dirsek 45 dereceye hareket eder, 50ms acceleration ile
                               // Moving the elbow to 45 degrees with an acceleration of 50ms
  delay(1000);                 // 1 saniye bekle
                               // Wait for 1 second

  armbot.glipperMotion(0, 50); // Kaydırma 0 dereceye hareket eder, 50ms acceleration ile
                               // Sliding to 0 degrees with an acceleration of 50ms
  delay(1000);                 // 1 saniye bekle
                               // Wait for 1 second

}
