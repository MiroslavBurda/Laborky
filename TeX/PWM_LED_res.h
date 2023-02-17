int x = 0;
int up = 1; // bool up = true;

void setup(){
    pinMode(L_R, OUTPUT);  
    pinMode(SW3, INPUT_PULLUP);
    ledcSetup (0, 1000 , 10); // create PWM
    // ledcSetup ( channel , freq , resolution )
    // channel = 0 - 15
    // resolution = 10 => 2^10 => 1024
    ledcAttachPin (L_R , 0); // ledcAttachPin (pin , channel)
}
void loop() // this part works in cycle
{  
    if (( digitalRead ( SW3 )) == LOW ) {
        if (up) {
            x = x + 250;
            if (x == 1000) up = 0;
        }            
        else {
            x = x - 250;
            if (x == 0) up = 1;
        }
    }
        ledcWrite (0, x);
        delay(200);
}
