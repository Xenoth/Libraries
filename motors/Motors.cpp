#include "Motors.h"

Motors::Motors(uint8_t pin_dir_A, uint8_t pin_pw_A, uint8_t pin_dir_B, uint8_t pin_pw_B)
{
	this->pin_dir_A=pin_dir_A;
	this->pin_dir_B=pin_dir_B;
	this->pin_pw_A=pin_pw_A;
	this->pin_pw_B=pin_pw_B;
}
		
void Motors::setup()
{
	pinMode(pin_dir_A, OUTPUT);
	pinMode(pin_dir_B, OUTPUT);
	pinMode(pin_pw_A, OUTPUT);
	pinMode(pin_pw_B, OUTPUT);
	
	setDirA(true);
	setDirB(true);
	setPwA(0);
	setPwB(0);
}