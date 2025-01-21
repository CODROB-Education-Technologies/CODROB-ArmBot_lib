#include <ARMBOT.h> // ARMBOT kütüphanesini projeye dahil ediyoruz
                    // Including the ARMBOT library into the project

// ARMBOT sınıfından bir nesne oluştur
// Create an object of ARMBOT class
ARMBOT armbot;

void setup()
{
    // Seriyi başlat
    // Start the serial communication
    Serial.begin(115200);
    Serial.println("ARMBOT Başlatılıyor..."); // Başlangıç mesajı
                                              // Initialization message

    // ARMBOT'u başlat
    // Initialize ARMBOT
    armbot.begin();

    // Kütüphaneyi test et
    // Test the library
    armbot.test();
    Serial.println("ARMBOT Başlatıldı ve Test Edildi!"); // Durum bilgisi
                                                         // Status information
}

void loop()
{
    // İstiklal Marşı çal
    // Play the Turkish National Anthem
    Serial.println("İstiklal Marşı çalınıyor..."); // Bilgilendirme mesajı
                                                   // Informational message
    armbot.istiklalMarsiCal();
    delay(5000); // 5 saniye bekle
                 // Wait for 5 seconds

    // Axis 1'i hareket ettir
    // Move Axis 1
    Serial.println("Axis 1 90 dereceye hareket ediyor..."); // Axis 1 hareket bilgisi
                                                            // Axis 1 movement information
    armbot.axis1Motion(90);                                 // 90 dereceye hareket
                                                            // Move to 90 degrees
    delay(1000);                                            // 1 saniye bekle
                                                            // Wait for 1 second

    // Axis 2'yi hareket ettir
    // Move Axis 2
    Serial.println("Axis 2 45 dereceye hareket ediyor..."); // Axis 2 hareket bilgisi
                                                            // Axis 2 movement information
    armbot.axis2Motion(45);                                 // 45 dereceye hareket
                                                            // Move to 45 degrees
    delay(1000);                                            // 1 saniye bekle
                                                            // Wait for 1 second

    // Axis 3'ü hareket ettir
    // Move Axis 3
    Serial.println("Axis 3 30 dereceye hareket ediyor..."); // Axis 3 hareket bilgisi
                                                            // Axis 3 movement information
    armbot.axis3Motion(30);                                 // 30 dereceye hareket
                                                            // Move to 30 degrees
    delay(1000);                                            // 1 saniye bekle
                                                            // Wait for 1 second

    // Glipper'ı hareket ettir
    // Move the gripper
    Serial.println("Glipper 10 dereceye hareket ediyor..."); // Glipper hareket bilgisi
                                                             // Gripper movement information
    armbot.glipperMotion(10);                                // 10 dereceye hareket
                                                             // Move to 10 degrees
    delay(1000);                                             // 1 saniye bekle
                                                             // Wait for 1 second
}
