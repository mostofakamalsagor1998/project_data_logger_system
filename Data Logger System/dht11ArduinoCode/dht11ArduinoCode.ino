//Name: Mostofa Kamal Sagor
//ID: 17301106
//CSE360(02)

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Let's Start!!!");
  dht.begin();
}

void loop() {
  delay(500);
  float humiditySensing  = dht.readHumidity();
  float tempSensing_Celsius = dht.readTemperature();
  float tempSensing_Fahrenheit = dht.readTemperature(true);
  if (isnan(humiditySensing) || isnan(tempSensing_Celsius)|| isnan(tempSensing_Fahrenheit)) {
    Serial.println("Sorry,couldn't read from the DHT11 Sensor!");
  }
  else{
    //float heatIndex1=dht.computeHeatIndex(tempSensing_Fahrenheit,humiditySensing);
    //float heatIndex2=dht.computeHeatIndex(tempSensing_Celsius,humiditySensing,false);
    
    Serial.println(tempSensing_Celsius);
    Serial.println(humiditySensing);
  } 
}
