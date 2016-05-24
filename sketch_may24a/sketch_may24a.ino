#include <IRremote.h>
#include <IRremoteInt.h>


int RECEIVE_PIN= 3;
IRrecv irreceiver(RECEIVE_PIN);
decode_results results;

 
void setup()
{
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  irreceiver.enableIRIn(); // Start the receiver
}
 
void loop() {  
   if (irreceiver.decode(&results)) {
      Serial.println(results.value, HEX);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(7, LOW);
      irreceiver.resume();
  }
    
  delay(100); //NEW LINE
}
    

