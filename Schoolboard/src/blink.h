void setup(){
    pinMode(L_R, OUTPUT); 
}

void loop(){
    digitalWrite(L_R, HIGH);
    delay(1000);
    digitalWrite(L_R, LOW);
    delay(1000);
}