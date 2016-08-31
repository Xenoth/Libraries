#ifndef RGBLed_h
#define RGBLed_h

#include "RGB.h"
#include "Led.h"

class RGBLed
{
	public :

		Led red, green, blue;

    RGBLed(){};
		RGBLed(uint8_t pin_red, uint8_t pin_green, uint8_t pin_blue);


		void setBrightnessAll(RGB brightness);
		void setFadeAll(int8_t fade_red, int8_t fade_green, int8_t fade_blue);


		void getBrightnessAll(RGB &brightness) const;
		void getFadeAll(int8_t &fade_red, int8_t &fade_green, int8_t &fade_blue) const;

		void turnOnAll();
		void turnOnAll(RGB brightness);

		void turnOffAll();


		void fadingAll();
		void fadingAll(int8_t fade_red, int8_t fade_green, int8_t fade_blue);

};

#endif
