int c = 0; // define integer 

void setup(){
    pinMode(SW0, INPUT_PULLUP);
    Serial.begin(115200); 
}

void loop(){
    if ( !digitalRead(SW0) ) c=c+1;
    Serial.println(c);
}