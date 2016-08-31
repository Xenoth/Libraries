#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer
{
	private :
		
		uint8_t pin;
	
	public :
		
		uint8_t volume;

    Buzzer(){};
		Buzzer(uint8_t pin);
		
		inline void setVoltage(uint8_t volume)		{this->volume=volume;}
		inline uint8_t getVoltage() const			{return volume;}
		
		inline void turnOn() const				{analogWrite(pin, volume);}
		void turnOn(uint8_t volume);
		
		void turnOff();
};

#endif
