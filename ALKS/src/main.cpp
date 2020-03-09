#include <Arduino.h>
#include "ALKS.h"


void setup() // this part run once
{
    setupAll(); // // initialize all LED digital pins as an output, SW pins as input etc., for more info press F12
    for(uint8_t i=0; i<2; i++) // 2x blink with all LED 
    {
        delay (500); // pause 500 miliseconds
        digitalWrite (L_R , HIGH ); // switch on red LED
        digitalWrite (L_Y , HIGH ); // switch on yellow LED
        digitalWrite (L_G , HIGH ); // switch on green LED
        digitalWrite (L_B , HIGH ); // switch on blue LED
        delay (500); 
        digitalWrite (L_R , LOW ); // switch off red LED
        digitalWrite (L_Y , LOW ); 
        digitalWrite (L_G , LOW ); 
        digitalWrite (L_B , LOW );
    }
    // L_RGB_R
    digitalWrite (L_RGB_R , HIGH ); // switch on red color in RGB LED
    delay (500);
    digitalWrite (L_RGB_R , LOW ); 
    delay (500);
    digitalWrite (L_RGB_G , HIGH ); // switch on green color in RGB LED
    delay (500);
    digitalWrite (L_RGB_G , LOW );
    delay (500);
    digitalWrite (L_RGB_B , HIGH ); // switch on blue color in RGB LED
    delay (500); 
    digitalWrite (L_RGB_B , LOW ); 
    delay (500);
    digitalWrite (L_RGB_R , HIGH );
    digitalWrite (L_RGB_G , HIGH );
    digitalWrite (L_RGB_B , HIGH );
    delay (500);
    digitalWrite (L_RGB_R , LOW );
    digitalWrite (L_RGB_G , LOW );
    digitalWrite (L_RGB_B , LOW );

    ledcSetup (0, 1000 , 10); // create PWM
    // ledcSetup ( channel , freq , resolution )
    // channel = 0 - 15
    // resolution = 10 => 2^10 => 1024
    ledcAttachPin (L_B , 0); // ledcAttachPin (pin , channel )
  
}

void loop() // this part works in cycle
{  
    if (( digitalRead ( SW1 )) == LOW ) // pushed switch 1 
        { digitalWrite (L_R , HIGH );}
    else { digitalWrite (L_R , LOW );}

    if (( digitalRead ( SW2 )) == LOW )
        { digitalWrite (L_Y , HIGH );}
    else { digitalWrite (L_Y , LOW );}

    if (( digitalRead ( SW3 )) == LOW )
        { digitalWrite (L_G , HIGH );}
    else { digitalWrite (L_G , LOW );}

    ledcWrite (0, analogRead ( POT1 )/4); // potentiometer connect


}