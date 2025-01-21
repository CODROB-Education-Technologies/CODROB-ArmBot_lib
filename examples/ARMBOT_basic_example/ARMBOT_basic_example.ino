#include <ARMBOT.h> // ARMBOT kütüphanesini projeye dahil ediyoruz
                    // Including the ARMBOT library into the project

ARMBOT armbot; // ARMBOT sınıfından bir nesne oluşturuyoruz
               // Creating an object of the ARMBOT class

void setup()
{
  Serial.begin(115200);                 // Seri haberleşmeyi başlatıyoruz
                                        // Initializing serial communication
  armbot.begin();                       // ARMBOT nesnesinin başlatma fonksiyonunu çağırıyoruz
                                        // Calling the initialization function of the ARMBOT object
  Serial.println("ARMBOT Başlatıldı!"); // Durum bilgisi yazdırıyoruz
                                        // Printing status information
}

void loop()
{
  // Buzzer bir nota çalar
  // Buzzer plays a note
  armbot.calBuzzer(440, 500); // Frekansı 440Hz, süresi 500ms
                              // Frequency of 440Hz, duration of 500ms
  delay(1000);                // 1 saniye bekle
                              // Wait for 1 second

  // Eksen 1 döner
  // Axis 1 rotates
  armbot.axis1Motion(90); // Dönme hareketi 90 derece
                          // Rotate to 90 degrees
  delay(1000);            // 1 saniye bekle
                          // Wait for 1 second

  // Eksen 2 hareket eder
  // Axis 2 moves
  armbot.axis2Motion(45); // Omuz hareketi 45 derece
                          // Move the shoulder to 45 degrees
  delay(1000);            // 1 saniye bekle
                          // Wait for 1 second

  // Eksen 3 hareket eder
  // Axis 3 moves
  armbot.axis3Motion(30); // Dirsek hareketi 30 derece
                          // Move the elbow to 30 degrees
  delay(1000);            // 1 saniye bekle
                          // Wait for 1 second

  // Glipper kapanır
  // Glipper closes
  armbot.glipperMotion(10); // Kaydırma hareketi 10 derece
                            // Slide to 10 degrees
  delay(1000);              // 1 saniye bekle
                            // Wait for 1 second
}
