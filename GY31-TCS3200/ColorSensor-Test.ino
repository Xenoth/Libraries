#include "GY31TCS3200.h"
#include <RGBLed.h>

#define RGBLedRed 3
#define RGBLedGreen 5
#define RGBLedBlue 6

#define S0Pin 11
#define S1Pin 10
#define S2Pin 9
#define S3Pin 8
#define ledPin 12
#define outputPin 7

RGBLed led(RGBLedRed, RGBLedGreen, RGBLedBlue);
GY31TCS3200 GY31(S0Pin, S1Pin, S2Pin, S3Pin, ledPin, outputPin);


void setup() {
  GY31.setup();
  Serial.begin(9600);
}

void loop() {

  Color res=GY31.scan();

  Serial.print("====================\nDetected : ");
  Serial.println(res);
  Serial.print("\n\tRed=");
  Serial.print(GY31.redPercent);
  Serial.print("%\n\tGreen=");
  Serial.print(GY31.greenPercent);
  Serial.print("%\n\tBlue=");
  Serial.print(GY31.bluePercent);
  Serial.print("%\n\nclearFreq=");
  Serial.print(GY31.clearFreq);
  Serial.println("ms\n\n");
  
  if(res==red)
    led.red.turnOn(255);
  else if(res==green)
    led.green.turnOn(255);
  else if(res==blue)
    led.blue.turnOn(255);
  
  delay(500);
  led.turnOffAll();
}
