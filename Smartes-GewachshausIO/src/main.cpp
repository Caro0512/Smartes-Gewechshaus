#include <Arduino.h>

const int sensor = 34;

void setup() {
  Serial.begin(115200); 
  Serial.println("Ausgabe funktionsfähig:");
}

void loop() {
  int sensorValue = analogRead(sensor);
  Serial.println(sensorValue);
  
  delay(500); 
}