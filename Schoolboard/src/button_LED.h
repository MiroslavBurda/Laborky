void setup(){
    Serial.begin(115200);
    pinMode(SW1, INPUT_PULLUP); 
    pinMode(L_R, OUTPUT);  
    delay(10); // needed for stabilization
}
void loop(){
   if (( digitalRead ( SW1 )) == LOW ) 
        { digitalWrite (L_R, HIGH );}
    else { digitalWrite (L_R, LOW );}
} 