#include "RGB.h"

RGB::RGB(){}
	
RGB::RGB(uint8_t red, uint8_t green, uint8_t blue)
{
	setRed(red);
	setGreen(green);
	setBlue(blue);
}

RGB::RGB(const RGB &color)
{
	setRed(color.red);
	setGreen(color.green);
	setBlue(color.blue);
}
