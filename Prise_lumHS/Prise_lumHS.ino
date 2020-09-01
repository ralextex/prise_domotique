int trigger=9;                               // Der Trigger Pin
int echo=10;                                  // Der Echo Pin
int pinS = 8;

long dauer=0;                                // Hier wird die Zeitdauer abgespeichert

                                             // die die Ultraschallwelle braucht

                                             // um zum Sensor zurückzukommen

long entfernung=0;                           // Hier wird die Entfernung vom 

                                             // Hindernis abgespeichert

 

void setup(){
    pinMode(trigger, OUTPUT);                // Trigger Pin als Ausgang definieren
    pinMode(pinS, OUTPUT);
    pinMode(echo, INPUT);                    // Echo Pin als Eingang defnieren
    digitalWrite(pinS, LOW);
}

 

void loop()

{
 

    digitalWrite(trigger, LOW);              // Den Trigger auf LOW setzen um

                                             // ein rauschfreies Signal

                                             // senden zu können

    delay(5);                                // 5 Millisekunden warten

    digitalWrite(trigger, HIGH);             // Den Trigger auf HIGH setzen um eine 

                                             // Ultraschallwelle zu senden

    delay(10);                               // 10 Millisekunden warten

    digitalWrite(trigger, LOW);              // Trigger auf LOW setzen um das 

                                             // Senden abzuschließen

    dauer = pulseIn(echo, HIGH);             // Die Zeit messen bis die 

                                             // Ultraschallwelle zurückkommt

    entfernung = (dauer/2) / 29.1;           // Die Zeit in den Weg in Zentimeter umrechnen

    if(entfernung < 60){
      digitalWrite(pinS, !digitalRead(pinS));
    }

    delay(2000);                             // Nach einer Sekunde wiederholen

 

}

  
