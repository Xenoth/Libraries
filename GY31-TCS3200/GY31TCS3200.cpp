#include "GY31TCS3200.h"

GY31TCS3200::GY31TCS3200(uint8_t S0Pin, uint8_t S1Pin, uint8_t S2Pin, uint8_t S3Pin, uint8_t ledPin, uint8_t outputPin)
{
    this->S0Pin=S0Pin;
    this->S1Pin=S1Pin;
    this->S2Pin=S2Pin;
    this->S3Pin=S3Pin;
    this->ledPin=ledPin;
    this->outputPin=outputPin;

}

void GY31TCS3200::setup()
{
    pinMode(S0Pin, OUTPUT);
    pinMode(S1Pin, OUTPUT);
    pinMode(S2Pin, OUTPUT);
    pinMode(S3Pin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(outputPin, INPUT);
}

Color GY31TCS3200::scan()
{
    clearFreq=getFreqClear();
    redPercent=(clearFreq/getFreqRed())*100;
    greenPercent=((clearFreq/getFreqGreen())*100)*1.25;
    bluePercent=((clearFreq/getFreqBlue())*100)*0.79;

  if (clearFreq>10)
    return black;    
  else if((redPercent>greenPercent) && (redPercent>bluePercent))
  {
      return red;
  }
  else if((greenPercent>redPercent) && (greenPercent>bluePercent))
  {
      return green;
  }
  else if((bluePercent>greenPercent) && (bluePercent>redPercent))
  {
      return blue;
  }
  else 
    return white;
}

//private

void GY31TCS3200::scalingOn()
{
  digitalWrite(S0Pin, HIGH);
  digitalWrite(S1Pin, HIGH);
}

void GY31TCS3200::scalingOff()
{
  digitalWrite(S0Pin, LOW);
  digitalWrite(S1Pin, LOW);
}

float GY31TCS3200::getFreqOutput()
{
  this->lightsOn();
  this->scalingOn();

  if(digitalRead(outputPin)==LOW)
  {
    pulseIn(outputPin, HIGH);
  }

  pulseIn(outputPin, LOW);

  float ms = pulseIn(outputPin, HIGH);

  this->lightsOff();
  this->scalingOff();

  return ms;
}

float GY31TCS3200::getFreqRed()
{
  digitalWrite(S2Pin, LOW);
  digitalWrite(S3Pin, LOW);

  return getFreqOutput();
}

float GY31TCS3200::getFreqGreen()
{
  digitalWrite(S2Pin, HIGH);
  digitalWrite(S3Pin, HIGH);

 return getFreqOutput();
}

float GY31TCS3200::getFreqBlue()
{
  digitalWrite(S2Pin, LOW);
  digitalWrite(S3Pin, HIGH);

  return getFreqOutput();
}

float GY31TCS3200::getFreqClear()
{
  digitalWrite(S2Pin, HIGH);
  digitalWrite(S3Pin, LOW);

  return getFreqOutput();
}
