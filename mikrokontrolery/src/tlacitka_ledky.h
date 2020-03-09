#include <Arduino.h>

void setup(){
    pinMode(21, OUTPUT);
    pinMode(26, INPUT_PULLUP); 
}

void loop(){
    digitalWrite(21, !digitalRead(26));
}