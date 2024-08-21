#include <Arduino.h>
#include "Display.h"
#include "Dht110.h"

#define SOIL_MOISTURE_PIN A0
#define RELAY_PIN 7

DP display(128, 64, -1);
DHT dhtSensor(2, DHT11);


void setup() 
{
    display.begin();
    delay(2000);
    display.clearDisplay();
    display.renderText("Hello World");
    delay(2000);
    display.clearDisplay();

    if(![]() -> bool {
        dhtSensor.begin();
        return true;
    }())//lambda function
    {
        display.renderText("!DHT11");
        delay(2000);
        display.clearDisplay();
    }
    else
    {
        display.renderText("DHT11");
        delay(2000);
        display.clearDisplay();
    }
}

void loop() 
{ 
    float temperature = dhtSensor.readTemperature();
    float humidity = dhtSensor.readHumidity();
    
    bool coolerOn = (SOIL_MOISTURE_PIN < 500) || (temperature > 25.0);
    int soilMoistureValue = map(analogRead(SOIL_MOISTURE_PIN), 0, 1023, 0, 100);
    
    
    if(isnan(temperature) || isnan(humidity))
    {
        display.renderText("Error");
        delay(2000);
        display.clearDisplay();
    }
    else
    {
        display.renderText("T: " + String(temperature) + "C");
        delay(2000);
        display.clearDisplay();
        display.renderText("H: " + String(humidity) + "%");
        delay(2000);
        display.clearDisplay();
        display.renderText("SM: " + String(soilMoistureValue) + "%");
        delay(2000);
        display.clearDisplay();
    }

    if(coolerOn)
    {
        digitalWrite(RELAY_PIN, HIGH);
        display.renderText("Cooler On");
    }
    else
    {
        digitalWrite(RELAY_PIN, LOW);
        display.renderText("Cooler Off");
    }
    delay(2000);
}