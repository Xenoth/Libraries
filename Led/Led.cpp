#include "Led.h"

Led::Led(uint8_t pin)
{
    this->pin=pin;
}

Led::Led(uint8_t pin, uint8_t brightness, int8_t fade)
{
    setBrightness(brightness);
    setFade(fade);
    this->pin=pin;
}

void Led::turnOn(uint8_t brightness)
{
    setBrightness(brightness);
    turnOn();
}

void Led::turnOff()
{
   turnOn(0);
   brightness=0;
}

void Led::fading()
{
    if(brightness+fade>255)
	{
		fade=fade*(-1);
		brightness=255;
	}
	else if (brightness+fade<0)
	{
		fade=fade*(-1);
		brightness=0;
	}
	else
		brightness=brightness+fade;
    turnOn();
}

void Led::fading(int8_t fade)
{
    setFade(fade);
    fading();
}
