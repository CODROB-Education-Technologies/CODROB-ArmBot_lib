//
//        CODROB - ArmBot Test yazılımı.
//
//

// Joystick  X ekseni ile dirsek (27) motoru kontrol ediliyor.
// Joystick Y Ekseni ile Omuz (26) motoru kontrol ediliyor.
// Potansiyometre ile Dönel (25) motor kontrol ediliyor.
// Encoder Butonu ile Parmak (32) motoru kontrol ediliyor.
// IO0 Butonu ile Buzzer (33) kontrol ediliyor.
//
// Mantık: Joystick yukarı sağa doğru gittikçe robot kol öne doğru uzanır.
// Geri sola doğru gittikçe de robot kol geri doğru döner.
// Buzzer butonuna basıldığında 250ms boyunca ses çıkartır.
// Tüm eksenlerin açı değerlerini ekranda gösterir.

#include <ESP32Servo.h>        // ESP32Servo kütüphanesi dahil edildi
#include <Wire.h>              // I2C haberleşmesi için Wire kütüphanesi
#include <LiquidCrystal_I2C.h> // LCD ekran kontrolü için

// ** Pin Tanımlamaları **
const int parmakServo_IO32 = 32;   // Servo motor 32. pin
const int donelServo_IO25 = 25;    // Servo motor 25. pin
const int omuzServo_IO26 = 26;     // Servo motor 26. pin
const int dirsekServo_IO27 = 27;   // Servo motor 27. pin
const int encoderButton_IO13 = 13; // Encoder butonu
const int potantiomer_IO36 = 36;   // Potansiyometre
const int joystickX_IO34 = 34;     // Joystick X ekseni
const int joystickY_IO15 = 15;     // Joystick Y ekseni
const int buzzer_IO33 = 33;        // Buzzer
const int buttonBuzzer_IO0 = 0;    // Buzzer butonu

// ** Servo Motor Nesneleri **
Servo ParmakServo;
Servo DonelServo;
Servo OmuzServo;
Servo DirsekServo;

// ** LCD Ekran Tanımları **
LiquidCrystal_I2C lcd(0x27, 20, 4); // LCD adresi 0x27, boyut 20x4

// ** Değişkenler **
int ButtonStateEncoder = 0;
int lastButtonStateEncoder = 0;
int parmak32 = 60, lastParmakServoPos = -1;
int Donel25 = 90, lastDonelServoPos = -1;
int Omuz26 = 70, lastOmuzServoPos = -1;
int Dirsek27 = 60, lastDirsekServoPos = -1;

void setup()
{
    // ** Pin Modları **
    pinMode(encoderButton_IO13, INPUT_PULLUP); // Encoder butonu
    pinMode(buttonBuzzer_IO0, INPUT_PULLUP);   // Buzzer kontrol butonu
    pinMode(potantiomer_IO36, INPUT);          // Potansiyometre
    pinMode(joystickX_IO34, INPUT);            // Joystick X ekseni
    pinMode(joystickY_IO15, INPUT);            // Joystick Y ekseni
    pinMode(buzzer_IO33, OUTPUT);              // Buzzer

    // ** Servo Motorların Başlatılması **
    ParmakServo.attach(parmakServo_IO32);
    DonelServo.attach(donelServo_IO25);
    OmuzServo.attach(omuzServo_IO26);
    DirsekServo.attach(dirsekServo_IO27);

    // Servo motorları başlangıç açılarına ayarla
    ParmakServo.write(parmak32);
    DonelServo.write(Donel25);
    OmuzServo.write(Omuz26);
    DirsekServo.write(Dirsek27);

    // ** LCD Ekran Başlatılması **
    lcd.init();
    lcd.backlight();
    lcd.setCursor(7, 0);
    lcd.print("CODROB");
    lcd.setCursor(3, 1);
    lcd.print("ArmBot Kontrol");
    delay(4000);
}

void loop()
{
    // ** 32. Motor için Encoder Butonu Kontrolü **
    ButtonStateEncoder = digitalRead(encoderButton_IO13);
    if (ButtonStateEncoder == LOW && lastButtonStateEncoder == HIGH)
    {
        parmak32 = (parmak32 == 60) ? 0 : 60; // Konumu değiştir
        ParmakServo.write(parmak32);
        delay(200); // Buton debouncing
    }
    lastButtonStateEncoder = ButtonStateEncoder;

    // ** 25. Motor için Potansiyometre Kontrolü **
    Donel25 = map(analogRead(potantiomer_IO36), 0, 4095, 0, 180);
    DonelServo.write(Donel25);

    // ** 26. Motor için Joystick X Ekseni Kontrolü **
    Omuz26 = map(analogRead(joystickX_IO34), 0, 4095, 0, 180);
    OmuzServo.write(Omuz26);

    // ** 27. Motor için Joystick Y Ekseni Kontrolü **
    Dirsek27 = map(analogRead(joystickY_IO15), 0, 4095, 0, 180);
    DirsekServo.write(Dirsek27);

    // ** LCD Ekranda Servo Motor Açılarını Güncelleme **
    if (parmak32 != lastParmakServoPos)
    {
        lcd.setCursor(0, 2);
        lcd.print("Parmak:");
        lcd.setCursor(7, 2);
        lcd.print(parmak32);
        lastParmakServoPos = parmak32;
    }
    if (Donel25 != lastDonelServoPos)
    {
        lcd.setCursor(10, 2);
        lcd.print("Donel:");
        lcd.setCursor(16, 2);
        lcd.print(Donel25);
        lastDonelServoPos = Donel25;
    }
    if (Omuz26 != lastOmuzServoPos)
    {
        lcd.setCursor(0, 3);
        lcd.print("Omuz: ");
        lcd.setCursor(5, 3);
        lcd.print(Omuz26);
        lastOmuzServoPos = Omuz26;
    }
    if (Dirsek27 != lastDirsekServoPos)
    {
        lcd.setCursor(10, 3);
        lcd.print("Dirsek:");
        lcd.setCursor(17, 3);
        lcd.print(Dirsek27);
        lastDirsekServoPos = Dirsek27;
    }

    // ** Buzzer Kontrolü **
    if (digitalRead(buttonBuzzer_IO0) == LOW)
    {
        tone(buzzer_IO33, 750, 250); // 250ms buzzer sesi
    }

    delay(20); // Döngü gecikmesi
}
