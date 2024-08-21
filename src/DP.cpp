#include "Display.h"

DP::DP(uint8_t w, uint8_t h, int8_t rst_pin)
{
    this->w = w;
    this->h = h;
    this->rst_pin = rst_pin;
    this->initMessage="";

    this->display = Adafruit_SSD1306(w, h, &Wire, -1);
}

void DP::render()
{
    this->display.display();
}

void DP::clearDisplay()
{
    this->display.clearDisplay();
}

void DP::begin()
{
    this->display.setTextSize(1);
    this->display.setTextColor(SSD1306_WHITE);
    this->display.setCursor(0,0);
    
    this->display.begin(SSD1306_SWITCHCAPVCC, 0x3C);//talvez precise citar isso, mas não tenho certeza ainda kkk;
    if(!this->display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        for(;;);
    }
    
    for(;;)
    {
        initMessage += ".";
        this->display.println("Iniciando"+initMessage);
        if(initMessage.length() == 2)
            break;
        this->display.display();
    }
}

void DP::renderText(String text)
{
    this->display.setTextSize(1);
    this->display.setTextColor(SSD1306_WHITE);
    this->display.setCursor(0,0);
    this->display.println(text);
    this->display.display();
}

void DP::renderText(String text, uint8_t size, uint8_t color, uint8_t x, uint8_t y)
{
    this->display.setTextSize(size);
    this->display.setTextColor(color);
    this->display.setCursor(x,y);
    this->display.println(text);
}