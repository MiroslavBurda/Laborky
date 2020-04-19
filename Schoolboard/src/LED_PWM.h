#include <Arduino.h>
#include "pinout.h"

int x = 0;

void setup(){
    pinMode(L_R, OUTPUT);  
    ledcSetup (0, 1000 , 10); // create PWM
    // ledcSetup ( channel , freq , resolution )
    // channel = 0 - 15
    // resolution = 10 => 2^10 => 1024
    ledcAttachPin (L_R , 0); // ledcAttachPin (pin , channel)
}
void loop() // this part works in cycle
{  
    for (x = 0; x < 1030; x = x+10 ) {
        ledcWrite (0, x);
        delay(10);
    }
    for (x = 1020; x > 0; x = x-10 ) {
        ledcWrite (0, x);
        delay(10);
    }
}
