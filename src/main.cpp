#include <Arduino.h>
#include "Display.h"
#include "Dht110.h"

#define SOIL_MOISTURE_PIN A0
#define RELAY_PIN 7

DP display(128, 64, -1);
DHT dhtSensor(2, DHT11);
bool coolerOn;


void setup() 
{
    pinMode(RELAY_PIN, OUTPUT);
    Serial.begin(9600);
    display.begin();
    delay(2000);
    display.clearDisplay();
    display.renderText("Teste de Display");
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
    
    
    
    int soilMoistureValue = map(analogRead(SOIL_MOISTURE_PIN), 0, 1023, 100, 0);
    (float)soilMoistureValue < 35 ? coolerOn = 0x1 : coolerOn = 0x0;
    
    if(isnan(temperature) || isnan(humidity))
    {
        
        display.renderText("Error");
        delay(2000);
        display.clearDisplay();
    }
    else
    {
        if(coolerOn)
        {
            digitalWrite(RELAY_PIN, 1);
            display.renderText("Cooler On", 1, SSD1306_WHITE, 0, 20);
            
        }
        else
        {
            digitalWrite(RELAY_PIN, 0);
            display.renderText("Cooler Off", 1, SSD1306_WHITE, 0, 20);
        }

        display.renderText("T: " + String(temperature) + "C", 1, SSD1306_WHITE, 0, 30);
        display.renderText("H: " + String(humidity) + "%", 1, SSD1306_WHITE, 0, 40);
        display.renderText("UM_S: " + String(soilMoistureValue) + "%", 1, SSD1306_WHITE, 0, 50);
        display.render();
        delay(500);
        display.clearDisplay();
        delay(400);
    }
    Serial.println(String(humidity) + "HUMIDADE");
    Serial.println(String(temperature) +"TEMPERATUA");
    Serial.println(String(soilMoistureValue) + "HUmidade do solo");
    Serial.println(String(analogRead(SOIL_MOISTURE_PIN)) + "Valor do sensor de umidade do solo");
   
}