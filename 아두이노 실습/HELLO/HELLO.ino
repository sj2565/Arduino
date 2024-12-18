#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  lcd.init();
  lcd.backlight();
}

void loop(){
  lcd.setCursor(0,0);

  lcd.print("HELLO");

  delay(1000);
  lcd.clear();
}
