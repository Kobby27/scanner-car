#include <Arduino.h>
#include "main.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void lcdSetup()
{
    lcd.init(); // initialize the lcd

    // Print a message to the LCD.
    lcd.backlight();
    Wire.begin(21, 22);
}

void displayDistance(){
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print(distance);
    lcd.setCursor(7, 1);
    lcd.print("mm");
}
