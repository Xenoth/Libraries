#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{
    private :
        uint8_t pin;

    public :
        uint8_t brightness;
        int8_t fade;

        Led(){};
        Led(uint8_t pin);
        Led(uint8_t pin, uint8_t brightness, int8_t fade);

        inline void setBrightness(uint8_t brightness)   {this->brightness=brightness;}
        inline void setFade(int8_t fade)                {this->fade=fade;}

        inline uint8_t getBrightness() const            {return brightness;}
        inline uint8_t getFade() const                  {return fade;}

        inline void turnOn() const                      {analogWrite(pin, brightness);}
        void turnOn(uint8_t brightness);

        void turnOff();

        void fading();
        void fading(int8_t fade);
};

#endif
