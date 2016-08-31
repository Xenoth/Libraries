#include "HYSRF05.h"

HYSRF05::HYSRF05(uint8_t trigPin, uint8_t echoPin)
{
    this->trigPin=trigPin;
    this->echoPin=echoPin;
}

void HYSRF05::setup()
{
    pinMode(trigPin, OUTPUT);
    digitalWrite(trigPin, LOW);
    delay(50);
    pinMode(echoPin, INPUT);
}

int HYSRF05::scan()
{
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    int ms=pulseIn(echoPin, HIGH);
    
    delay(50);
    
    return miliseconds2Centimeters(ms);
}

boolean HYSRF05::inRange(int centimeters)
{
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    float msRange=centimeters2Miliseconds(centimeters);

    float ms=pulseIn(echoPin, HIGH, msRange);
    return (ms<=msRange);
}
