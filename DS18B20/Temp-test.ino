
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "DS18B20.h"

#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);
double tempRes;
DS18B20 temp(4);


void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(1000);
  
  display.clearDisplay();

  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Temp-Test software");
  display.display();
  temp.search();
  delay(1000);
  
  display.clearDisplay();
  
  
  
}

void loop() {
  while(1)
  {
    display.setCursor(0,0);
    display.clearDisplay();
    display.println("Searching...");
    display.print("Search : ");
    display.println(temp.search());
    if(temp.getTemp(&tempRes))
    {
      display.print("\nTemp=");
      display.print(tempRes);
      display.display();
      delay(800);
    }
    else
    {
      display.print("\nNo data");
      display.display();
      delay(100);
    }
    
  }

}
