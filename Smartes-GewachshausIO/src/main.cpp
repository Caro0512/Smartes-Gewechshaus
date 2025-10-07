#include <Arduino.h>
#include "DHT.h"

// --- Pin-Definitionen ---
const int BODEN_SENSOR_PIN = 34; 
#define DHTPIN 18                
#define DHTTYPE DHT11

// --- Sensor-Initialisierung ---
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200); 
  Serial.println("Kombinierter Sensor-Test gestartet!");
  
  dht.begin(); 
}

void loop() {
  
  int bodenWert = analogRead(BODEN_SENSOR_PIN);


  float luftfeuchte = dht.readHumidity();


  Serial.print("Bodenfeuchtigkeit (Rohwert): ");
  Serial.println(bodenWert);

 
  if (isnan(luftfeuchte)) {
    Serial.println("Fehler beim Auslesen des DHT11 Sensors!");
  } else {
    Serial.print("Luftfeuchtigkeit: ");
    Serial.print(luftfeuchte);
    Serial.println("%");
  }
  Serial.println("------------------------------------");


  delay(2000);
}