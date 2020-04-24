int pushed = 0;
long time1 = 0;

void setup(){
    Serial.begin(115200);
    pinMode(SW1, INPUT_PULLUP); 
    pinMode(L_R, OUTPUT);  
    delay(10); // needed for stabilization
}
void loop(){
   if (( digitalRead ( SW1 )) == LOW ) {
        if ( pushed == 0 ) {
            digitalWrite (L_R, HIGH );
            pushed = 1;
            time1 = millis();
        }           
    }
    if ( (millis() - time1 > 1500) and (time1 > 0) ) {
        digitalWrite (L_R, LOW );
        pushed = 0;
    }
}
