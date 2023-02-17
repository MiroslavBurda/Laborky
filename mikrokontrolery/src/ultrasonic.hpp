#pragma once
#include "pinout.h"

// pro možnost jednoduchých uprav přehlednejšího kodu použití
// define pro přejmenování pinu
#define TRIG GPIO_NUM_33
#define ECHO GPIO_NUM_32

unsigned long duration;

void setup()
{
    pinMode(TRIG, OUTPUT); // nastavím pin trigru jako výstupní
    pinMode(ECHO, INPUT_PULLUP); // nastavím pin echo jako vstupní s pullupem

    Serial.begin(115200); // nastavím komunikační rychlost sériové linky
}

void loop()
{
    digitalWrite(TRIG, HIGH); // nastavim trigr na log 1
        //a tím začátek výsílání ultrazvukového signálu
    delayMicroseconds(10); // 10 mikrosekund čekání
    digitalWrite(TRIG, LOW); // nastavim trigr na log 0
        //a tím konec výsílání ultrazvukového signálu
    duration = pulseIn(ECHO, HIGH); // měření času
        //do zmeni hodnoty pinu echo (přijetí zvukového signálu)
    Serial.println(duration*0.034/2); // vypsání
        // naměřené vzdálenosti (čas převedený na vzdálenost
        // a vydělený dvěmi protože zvyk letí tam a spět)
    delay(500); // 500 milisekund čekání
}