void setup(){
    pinMode(SW0, INPUT_PULLUP);
    Serial.begin(115200); 
}

void loop(){
    Serial.print(!digitalRead(SW0));
    Serial.println(digitalRead(SW0) ? ": VYPNUTO" : ": ZAPNUTO");
}