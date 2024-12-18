#include <LiquidCrystal_I2C.h>
#include <DHT11.h>
#include <Wire.h>

#define Atomizer A0

LiquidCrystal_I2C lcd(0x27,16,2);

int pin=7;
DHT11 dht11(pin);

void setup()
{
  lcd.init();
  Serial.begin(9600);
  pinMode(Atomizer, OUTPUT);
}

void loop()
{
  float h;

  if(h>=70)
  {
    digitalWrite(Atomizer,LOW);
  }

  lcd.backlight();
  lcd.display();
  lcd.print("H ");
  lcd.print(h,1);
  lcd.print(" %");

   if(h<70)
   {
    digitalWrite(Atomizer,HIGH);
    lcd.print("On");
   }
   delay(1500);
   lcd.clear();
}
