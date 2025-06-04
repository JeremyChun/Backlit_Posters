/*Code uses IRremote library version 3.6.0*/

#include "IRremote.h"
#define receiver 2 
int LED = 1;

IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'

void setup()
{

  irrecv.enableIRIn(); // Start receiver

  pinMode(LED, OUTPUT); // MOSFET on PIN 1

  digitalWrite(LED, LOW); // Start LEDs off

}

void loop()
{

  if (irrecv.decode(&results)) // poll IR signal
  {
    // ON
    if (results.value==0xFF30CF)
    {   
         analogWrite(LED, 100);
    }  
    // OFF  
    else if (results.value==0xFF18E7)
    { 
      digitalWrite(LED, LOW);
    }
    // DIM
    else if (results.value==0xFF7A85)
    {
      analogWrite(LED, 40);
    }
    // NIGHT
        else if (results.value==0xFF10EF)
    {
      analogWrite(LED, 10);
    }
     
    irrecv.resume(); // resume polling
  }  
}