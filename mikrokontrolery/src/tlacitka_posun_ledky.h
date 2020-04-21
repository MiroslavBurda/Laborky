#include <Arduino.h>
#include "pinout.h"

int led = 0; // definuji řídící proměnou ledek
bool stisk = true; // definuji pomocnou proměnou tlačítka 

void setup()
{
    pinMode(LED_R, OUTPUT); // nastavení pinu pro ledku jako výstupní
    pinMode(LED_G, OUTPUT); // nastavení pinu pro ledku jako výstupní
    pinMode(LED_B, OUTPUT); // nastavení pinu pro ledku jako výstupní

    pinMode(SW3, INPUT_PULLUP); // nastavení pinu tlačítka jako vstupní s pullupem
}

void loop()
{
    if((!digitalRead(SW3))&&(stisk)) // při stisku tlačítka jednou vykonám obsah podmínky
    {
        stisk = false; // abych nevykonával podmínku pořád dokola
                       // nastavím pomocnou proměnou na false
        led++; // přičtu jedna k řídící proměnné 
        if(led>2) led = 0; // pokud má již proměnná moc velké číslo vrátím jí na nulu
    }
    else if (digitalRead(SW3))
        stisk = true; // pokud tlačítko není stisknuté nastavím pomocnou na true 
                      // abych mohl znovu přičítat
    switch(led) // podle řídící proměnné rozsvítím ledku
    {
    case 0:
        digitalWrite(LED_R, true);
        digitalWrite(LED_G, false);
        digitalWrite(LED_B, false);
        break;
    case 1:
        digitalWrite(LED_R, false);
        digitalWrite(LED_G, true);
        digitalWrite(LED_B, false);
        break;
    case 2:
        digitalWrite(LED_R, false);
        digitalWrite(LED_G, false);
        digitalWrite(LED_B, true);
        break;
    }
    delay(50); // počkám padesát milisekund 
}