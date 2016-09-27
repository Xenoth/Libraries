#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h> 

class Motors{
	
	public:
		
		Motors(uint8_t pin_dir_A, uint8_t pin_pw_A, uint8_t pin_dir_B, uint8_t pin_pw_B);
		
		void setup();
	
		inline void setDirA(bool dir) { digitalWrite(pin_dir_A, dir); };
		inline void setDirB(bool dir) { digitalWrite(pin_dir_B, dir); };
		inline void setPwA(uint8_t pw) { analogWrite(pin_pw_A, pw); };
		inline void setPwB(uint8_t pw) { analogWrite(pin_pw_B, pw); };
	
	private:
		uint8_t pin_dir_A;
		uint8_t pin_dir_B;
		uint8_t pin_pw_A;
		uint8_t pin_pw_B;

};


#endif