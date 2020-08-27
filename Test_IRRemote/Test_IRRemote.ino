#include <IRremote.h>

#define BUT_ON 16736925

int RECV_PIN = 11; //define input pin on Arduino 
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver 

  //LED DEBUG
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() { 
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }

  if(results.value == BUT_ON){
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}
