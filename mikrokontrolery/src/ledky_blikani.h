#include <Arduino.h>
#include "pinout.h"

void setup()
{
    pinMode(LED_R, OUTPUT); // nastavení pinu pro ledku jako výstupní
}

void loop()
{
    digitalWrite(LED_R, false); // nastavení výstupní hodnoty pinu na 0
    delay(500); //pul vteřiny čekání
    digitalWrite(LED_R, true); // nastavení výstupní hodnoty pinu na 1
    delay(500); //pul vteřiny čekání
    // a znovu od začátku složených závorek
}