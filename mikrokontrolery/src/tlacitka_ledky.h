#include <Arduino.h>
#include "pinout.h"

void setup()
{
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_B, OUTPUT);

    pinMode(SW3, INPUT_PULLUP);
}

void loop()
{
    digitalWrite(LED_R, !digitalRead(SW3));
    digitalWrite(LED_G, !digitalRead(SW3));
    digitalWrite(LED_B, !digitalRead(SW3));

    delay(10);
}