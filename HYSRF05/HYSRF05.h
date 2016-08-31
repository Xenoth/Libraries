#ifndef HYSRF05_H
#define HYSRF05_H

#include <Arduino.h>

class HYSRF05
{
    public:

        HYSRF05(uint8_t trigPin, uint8_t echoPin);

        void setup();

        //return distance, 450 if no obstacle detected
        int scan();

        //Return true if obstacle detected in this range
        boolean inRange(int centimeters);

    private:

        uint8_t trigPin, echoPin;

        inline int const miliseconds2Centimeters(int ms){ return (ms/58); };
        inline int const centimeters2Miliseconds(int cm){ return (cm*58); };
};

#endif
