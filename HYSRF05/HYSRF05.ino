#include "HYSRF05.h"

#define SONAR_TRIG_PIN 5
#define SONAR_ECHO_PIN 6

HYSRF05 sonar(SONAR_TRIG_PIN,SONAR_ECHO_PIN);

void setup() {
  sonar.setup();
  Serial.begin(9600);
}

void loop() {
  
  Serial.print(sonar.scan());
  Serial.println("cm\n");
  delay(2000);
}
