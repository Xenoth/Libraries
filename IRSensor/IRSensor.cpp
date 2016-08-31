#include "IRSensor.h"

IRSensor::IRSensor(uint8_t output_pin)
{
	this->output_pin = output_pin;
}

bool IRSensor::obstacleDetected()
{
	return (digitalRead(output_pin)==LOW);
}