#ifndef DS18B20_H
#define DS18B20_H

#define DS18B20_address 0x28

#include <OneWire.h>

class DS18B20 {

    public:

        DS18B20(uint8_t pin);
        ~DS18B20();

        /*
        0: No error
        1
        1: Not a OneWire Module
        2: Answer Corrupted
        3: Not a DS18B20 module
        */
        uint8_t search();

        inline boolean const detected(){ return isDetected; };
        
        boolean getTemp(double* temp);

    private:

        boolean isDetected;
        OneWire* ds;
        byte data[9], address[8];


};


#endif
