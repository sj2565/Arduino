#include <LiquidCrystal_I2C.h>
#include <DHT11.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int pin=7;
DHT11 dht11(pin);

void setup()
{
  lcd.init();
  Serial.begin(9600);
}

void loop()
{
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    lcd.backlight();
    lcd.display();
    lcd.print("TEMP: ");
    lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print("HUMI: ");
    lcd.print(humi);
  }
  else
  {
    lcd.backlight();
    lcd.display();
    lcd.print("Error No : ");
    lcd.print(err);
  }
  delay(1500);
  lcd.clear();
}
    
  
