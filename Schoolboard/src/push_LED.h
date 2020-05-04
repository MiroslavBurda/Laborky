int led = 0; // state variable
bool pressed = true; 

void setup()
{
    pinMode(L_R, OUTPUT); 
    pinMode(L_G, OUTPUT); 
    pinMode(L_B, OUTPUT); 
    pinMode(SW3, INPUT_PULLUP);
}

void loop()
{
    if((!digitalRead(SW3)) and (pressed)) // if SW3 pressed, this condition runs once
    {
        pressed = false;                        
        led++; // led = led + 1;
        if(led>2) led = 0; 
    }
    else if (digitalRead(SW3))
        pressed = true; 
                      
    switch(led) 
    {
    case 0:
        digitalWrite(L_R, true);
        digitalWrite(L_G, false);
        digitalWrite(L_B, false);
        break;
    case 1:
        digitalWrite(L_R, false);
        digitalWrite(L_G, true);
        digitalWrite(L_B, false);
        break;
    case 2:
        digitalWrite(L_R, false);
        digitalWrite(L_G, false);
        digitalWrite(L_B, true);
        break;
    }
    delay(50);
}