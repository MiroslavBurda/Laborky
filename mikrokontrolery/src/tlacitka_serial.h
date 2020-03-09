#include <Arduino.h>

void setup(){
    pinMode(26, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop(){
    Serial.println(!digitalRead(26));
    // Serial.println(digitalRead(26) ? "VYPNUTO" : "ZAPNUTO");
}