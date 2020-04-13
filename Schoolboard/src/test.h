void setup() // this part run once
{
    pinMode(L_R, OUTPUT);  // initialize red LED digital pin as an output
    pinMode(L_G, OUTPUT);
    pinMode(L_B, OUTPUT);
    pinMode(SW0, INPUT_PULLUP); // initialize button0 pin as input
    pinMode(SW1, INPUT_PULLUP); 
    pinMode(SW2, INPUT_PULLUP);
    pinMode(SW3, INPUT_PULLUP);
    
    for(uint8_t i=0; i<2; i++) // 2x blink with all LED 
    {
        delay (500); // pause 500 miliseconds
        digitalWrite (L_R , HIGH ); // switch on red LED
        digitalWrite (L_G , HIGH ); // switch on yellow LED
        digitalWrite (L_B , HIGH ); // switch on green LED
        delay (500); 
        digitalWrite (L_R , LOW ); // switch off red LED
        digitalWrite (L_G , LOW ); 
        digitalWrite (L_B , LOW ); 
    }

    Serial.begin(115200); // initialize UART, speed 115200 bit/s
}

void loop() // this part works in cycle
{  
   if (( digitalRead ( SW1 )) == LOW ) // pushed switch 1 
        { digitalWrite (L_B, HIGH );}
    else { digitalWrite (L_B, LOW );}

    if (( digitalRead ( SW2 )) == LOW )
        { digitalWrite (L_G, HIGH );}
    else { digitalWrite (L_G, LOW );}

    if (( digitalRead ( SW3 )) == LOW )
        { digitalWrite (L_R, HIGH );}          
    else { digitalWrite (L_R, LOW );}   

    Serial.println(!digitalRead(SW0));  // ! means negation 
    Serial.println(digitalRead(SW0) ? "VYPNUTO" : "ZAPNUTO"); // if (digitalRead(SW0) > 0) {Serial.println ("VYPNUTO");} else {Serial.println ("ZAPNUTO");}  }
    //  Ctrl+C will switch off terminal  
}
