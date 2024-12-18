#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Wire.h>

#define Atomizer A0
#define DHTpin 7
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27,16,2);


DHT dht(DHTpin, DHTTYPE);

void setup()
{
  lcd.init();
  Serial.begin(9600);
  pinMode(Atomizer, OUTPUT);
}

void loop()
{
  float humi = dht.readHumidity();
  
  if(humi>=70)
  {
    digitalWrite(Atomizer,LOW);
  }  
    lcd.backlight();
    lcd.display();
    lcd.print("HUMIDITY:  ");
    lcd.print(humi);

    if(humi<70)
    {
      digitalWrite(Atomizer.HIGH);
    }
    lcd.backlight();
    lcd.display();
    lcd.print("HUMIDITY:  ");
    lcd.print(humi);

    delay(1500);
    lcd.clear();
}

    

     
    

  
