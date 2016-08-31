#ifndef IRSENSOR_H
#define IRSENSOR_H

#include <Arduino.h>

class IRSensor
{
	private :
		
		uint8_t output_pin;
	
	public :

    IRSensor(){};
		IRSensor(uint8_t output_pin);
	
		bool obstacleDetected();
};

#endif
