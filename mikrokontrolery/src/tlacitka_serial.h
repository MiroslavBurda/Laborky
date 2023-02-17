#include <Arduino.h>
#include "pinout.h"

void setup()
{
    pinMode(SW3, INPUT_PULLUP); // nastavení pinu tlačítka jako vstupní s pullupem
    Serial.begin(115200); // nastavím komunikační rychlost sériové linky
}

void loop()
{
    Serial.println(digitalRead(SW3)); // přečtu stav tlačítka a vypíšu jej
    delay(250); // počkám čtvrt sekundy
}