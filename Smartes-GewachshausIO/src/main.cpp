#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200); 
  int result = myFunction(2, 3);
  Serial.println(result);
}

void loop() {
  // put your main code here, to run repeatedly:
  printf("Result: %d\n", myFunction(5, 7));
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}