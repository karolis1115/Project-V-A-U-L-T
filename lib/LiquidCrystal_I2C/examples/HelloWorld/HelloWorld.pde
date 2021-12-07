#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  lcd.backlight();
  lcd.init();
  lcd.clear();       
  //lcd.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Hello world!");
  
  lcd.setCursor(0,1);   //Move cursor to character 2 on line 1
  lcd.print("EEL1V.IC 2021-2022");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(500);
}