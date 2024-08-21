/**
 * @file DHTWrapper.H
 * @brief Header file for the credits of the project.
 * 
 * This file includes the necessary information about the author of the project.
 * It provides a link to the GitHub repository where the code is hosted.
 * 
 * @note This file assumes that the necessary libraries (Arduino.h) are already included.
 * 
 * Author: ArtumosGOC
 * GitHub: https://github.com/ArtumosGOC
 */
#include <DHT.h>
#include <Adafruit_Sensor.h>

class DHTWrapper {
public:
    DHTWrapper(uint8_t pin, uint8_t type);
    void begin();
    float getTemperature();
    float getHumidity();

private:
    DHT dht;
};
