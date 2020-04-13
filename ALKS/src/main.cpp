#include <Arduino.h>
#include "ALKS.h"

int p1 = 0, p2 = 0, a = 0; // define integer 
float cm = 0 ;      // define real 

void setup() // this part run once
{
    setupAll(); // // initialize all LED digital pins as an output, SW pins as input etc., for more info press F12
    Serial.begin(115200); // initialize UART, speed 115200 bit/s
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
    
    ledcSetup (0, 1000 , 10); // create PWM
    ledcSetup(1,1000, 10 );
    // ledcSetup ( channel , freq , resolution )
    // channel = 0 - 15
    // resolution = 10 => 2^10 => 1024
    ledcAttachPin (L_B , 0); // ledcAttachPin (pin , channel )
    ledcAttachPin (L_R , 1);
    printf("%i: %i ;", 1, analogRead ( POT1 )/4); // write data for serial monitor via UART 
    printf("%i: %i \n", 2, analogRead ( POT2 )/4); 
 
    p1 = analogRead (POT1); 
    p2 = analogRead (POT2); 
    printf("%i, %i, %3.2f \n", p1 + p2, 2*p1*p2, ( (float) p1-p2)/7 ); // %i - integer, %f - float, \n - new line
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

    printf("%i: %i ; ", 1, analogRead ( POT1 ) );
     printf("%i: %i \n", 2, analogRead ( POT2 ) );

 /*   delay (300); // pause 300 miliseconds
        digitalWrite (L_R , HIGH ); // switch on red LED
    delay (300); 
        digitalWrite (L_R , LOW ); // switch off red LED
if ( ( digitalRead ( SW1 )) == LOW )
{
    a=a+200;
    delay(500);
}
if ( ( digitalRead ( SW2 )) == LOW )
{
    a=0;
    delay(500);
}
; // potentiometer connect to PWM   */

ledcWrite (1, a); // potentiometer connect to PWM   

      printf("%i: %i ; ", 1, analogRead ( POT1 ) ); // write value of potenciometer
      printf("%i: %i \n", 2, analogRead ( POT2 ) );
    
ledcWrite (0, analogRead ( POT1 )/4); // potentiometer connect to PWM   - ahoj 



}