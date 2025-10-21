#include <Arduino.h>
#include "DHT.h"


const int Bodenfeutchtigkeit = 34; 
const float SwimmingPoolLevel = 14;
#define DHTPIN 18                
#define DHTTYPE DHT11

// --- Sensor-Initialisierung ---
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200); 
  Serial.println("Ausgabe funktioniert!");
  
  dht.begin(); 
  pinMode(SwimmingPoolLevel, INPUT_PULLUP);
}

void loop() {
  
  int bodenWert = analogRead(Bodenfeutchtigkeit);


  float luftfeuchte = dht.readHumidity();

  float poolLevel = digitalRead(SwimmingPoolLevel);


  Serial.print("Bodenfeuchtigkeit: ");
  Serial.println(bodenWert);

  Serial.print("Swimming Pool Level: ");
  Serial.println(poolLevel);

 
  if (isnan(luftfeuchte)) {
    Serial.println("Fehler beim Auslesen des Luftfeuchtigkeit Sensors!");
  } else {
    Serial.print("Luftfeuchtigkeit: ");
    Serial.print(luftfeuchte);
    Serial.println("%");
  }
  Serial.println("------------------------------------");


  delay(2000);
}