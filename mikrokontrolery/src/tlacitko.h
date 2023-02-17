#include <Arduino.h>
#include "pinout.h"

void setup(){
    pinMode(SW1, INPUT_PULLUP); 
    Serial.begin(115200);
}
void loop(){
    if(!digitalRead(SW1))
    {
        Serial.println("stisknuto");
    }
    else
    {
        Serial.println("nestisknuto");
    }
    delay(500);
}