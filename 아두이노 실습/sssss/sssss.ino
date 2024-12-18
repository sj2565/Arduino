#include <SevSeg.h>
#include <DHT.h>

SevSeg sevseg;
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
   sevseg.Begin(0,0,1,2,3,4,5,6,7,8,9,10,11);
   dht.begin();
}
 
void loop() {   
  
  float  humidity = dht.readHumidity();
  float  temperature = dht.readTemperature();
 
  String st3=String((int)temperature)+String((int)humidity);
  int sam_int=st3.toInt();  
  
  sevseg.NewNum(sam_int,2);  
  sevseg.PrintOutput(); 
  delay(3000); 
}
