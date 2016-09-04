#ifndef GY31TCS3200_H
#define GY31TCS3200_H

#include <Arduino.h>

enum Color{ red, green, blue, white, grey, black};

class GY31TCS3200
{
    public:

        float clearFreq, redPercent, bluePercent, greenPercent;


        GY31TCS3200(uint8_t S0Pin, uint8_t S1Pin, uint8_t S2Pin, uint8_t S3Pin, uint8_t ledPin, uint8_t outputPin);

        void setup();

        inline void lightsOn(){ digitalWrite(ledPin, HIGH); };
        inline void lightsOff(){ digitalWrite(ledPin, LOW); };


        Color scan();

    private:

        uint8_t S0Pin, S1Pin, S2Pin, S3Pin, ledPin, outputPin;

        void scalingOn();
        void scalingOff();

        float getFreqOutput();

        float getFreqRed();
        float getFreqBlue();
        float getFreqGreen();
        float getFreqClear();
};

#endif
