#include "Buzzer.h"

Buzzer::Buzzer(uint8_t pin)
{
	this->pin=pin;
}

void Buzzer::turnOn(uint8_t volume)
{
	this->volume=volume;
	turnOn();
}

void Buzzer::turnOff()
{
	volume=0;
	analogWrite(pin, volume);
}
