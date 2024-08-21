/**
 * @file DP.H
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

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>

class DP
{
    public:
        DP(uint8_t w, uint8_t h, int8_t rst_pin);

        void clearDisplay();

        void begin();

        void render();

        void renderText(String text, uint8_t size, uint8_t color, uint8_t x, uint8_t y);
        void renderText(String text);

        
    private:
        uint8_t w;
        uint8_t h;
        int8_t rst_pin;

        String initMessage;
        
        Adafruit_SSD1306 display;
};