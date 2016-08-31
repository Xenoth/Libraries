#include "RGBLed.h"

RGBLed::RGBLed(uint8_t pin_red, uint8_t pin_green, uint8_t pin_blue)
{
    red=Led(pin_red);
    green=Led(pin_green);
    blue=Led(pin_blue);
}


void RGBLed::setBrightnessAll(RGB brightness)
{
	red.setBrightness(brightness.red);
	green.setBrightness(brightness.green);
	blue.setBrightness(brightness.blue);
}

void RGBLed::setFadeAll(int8_t fade_red, int8_t fade_green, int8_t fade_blue)
{
	red.setFade(fade_red);
	green.setFade(fade_green);
	blue.setFade(fade_blue);
}

void RGBLed::getBrightnessAll(RGB &brightness) const
{
    brightness.red=red.brightness;
    brightness.green=green.brightness;
    brightness.blue=blue.brightness;
}

void RGBLed::getFadeAll(int8_t &fade_red, int8_t &fade_green, int8_t &fade_blue) const
{
    fade_red=red.fade;
    fade_green=green.fade;
    fade_blue=blue.fade;
}

void RGBLed::turnOnAll()
{
    red.turnOn();
    green.turnOn();
    blue.turnOn();
}

void RGBLed::turnOnAll(RGB brightness)
{
    red.turnOn(brightness.red);
    green.turnOn(brightness.green);
    blue.turnOn(brightness.blue);
}

void RGBLed::turnOffAll()
{
    red.turnOff();
    green.turnOff();
    blue.turnOff();
}

void RGBLed::fadingAll()
{
    red.fading();
    green.fading();
    blue.fading();
}

void RGBLed::fadingAll(int8_t fade_red, int8_t fade_green, int8_t fade_blue)
{
    red.fading(fade_red);
    green.fading(fade_green);
    blue.fading(fade_blue);
}
