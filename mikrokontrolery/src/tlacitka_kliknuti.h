#include <Arduino.h>

bool posledni_stav = 0;

void setup(){
    pinMode(26, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop(){
    if(digitalRead(26)==1){
        while (!digitalRead(26)==0)
        {
        }
        Serial.println("clicked");
    }
}