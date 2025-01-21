#include <ARMBOT.h>

// ARMBOT sınıfından bir nesne oluştur
// Create an object of ARMBOT class
ARMBOT armbot;

void setup()
{
    // Seriyi başlat
    // Start the serial communication
    Serial.begin(115200);

    // ARMBOT'u başlat
    // Initialize ARMBOT
    armbot.begin();

    // Kütüphaneyi test et
    // Test the library
    armbot.test();
}

void loop()
{
    // İstiklal Marşı çal
    // Play the Turkish National Anthem
    armbot.istiklalMarsiCal();
    delay(5000);

    // Axis 1'i hareket ettir
    // Move Axis 1
    armbot.axis1Motion(90, 10);
    delay(1000);

    // Axis 2'yi hareket ettir
    // Move Axis 2
    armbot.axis2Motion(45, 10);
    delay(1000);

    // Axis 3'ü hareket ettir
    // Move Axis 3
    armbot.axis3Motion(30, 10);
    delay(1000);

    // Glipper'ı hareket ettir
    // Move the gripper
    armbot.glipperMotion(10, 10);
    delay(1000);
}
