#include <LiquidCrystal_I2C.h>
#include <DHT11.h>
#include <Wire.h>

#define Atomizer A0        // Atomizer EN 핀 
 
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
  int err;
  float humi,temp;
  if((err=dht11.read(humi, temp))==0)
  {
    digitalWrite(Atomizer,LOW);
  }

  lcd.backlight();
  lcd.display();
  lcd.setCursor(0,0);
  lcd.print("HUMI: ");
  lcd.print(humi);
  
  if(humi<70)
  {
    digitalWrite(Atomizer,HIGH);
    lcd.setCursor(12,0);
    lcd.print("ON");
  }

  lcd.backlight();
  lcd.display();
  lcd.setCursor(0,1);
  lcd.print("TEMP: ");
  lcd.print(temp);
  
  delay(1500);
  lcd.clear();
}
