int pinS = 8;

float delai = 2;
unsigned long delai_ms;

unsigned long startTime;



void setup() {
  pinMode(pinS, OUTPUT);
  startTime = 0; 

  delai_ms = h2ms(delai);

  //start on rst
  startTime = millis();
  digitalWrite(pinS, HIGH);
}


void loop() {
    
    if(millis()- startTime > delai_ms){
       digitalWrite(pinS, LOW);
    }

}

unsigned long h2ms(float h){
  unsigned long ms = 1000UL * 60 * 60 * h;
  return ms;
}
