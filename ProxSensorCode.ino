#include <Zumo32U4.h>

Zumo32U4ProximitySensors proxSensors;

// Setup functie die voor voornamelijk de bit rate zorgt.

void setup(){
  // the bit rate (snelheid van communicatie) zetten wat 9600 (standaard) zal zijn 
  Serial.begin(9600)

//prox sensor initializeren  - Dit kan eventueel naar 2 of 3 zijn afhankelijk of dit naar de linesensor gaat of niet.
proxSensors.initThreeSensors();
}


// dit start de code.
void loop(){
  
}
