#include <Zumo32U4.h>

Zumo32U4ProximitySensors proxSensors;

// Setup functie die ervoor zorgt dat de programma runt

void setup(){
  // the bit rate zetten wat 9600 zal zijn
  Serial.begin(9600)

//prox sensor initializeren  - Dit kan eventueel naar 2 of 3 zijn afhankelijk of dit naar de linesensor gaat of niet.
proxSensors.initThreeSensors();
}
