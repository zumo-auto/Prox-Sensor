#include <Zumo32U4.h>

Zumo32U4ProximitySensors proxSensors;


// Setup functie die voor voornamelijk voor de instellingen voor de loop zorgen.

void setup(){
  // the bit rate (snelheid van communicatie) zetten wat 9600 (standaard) zal zijn 
  Serial.begin(4800); // 4800 // 9600

//prox sensor initializeren  - Dit kan eventueel naar 2 of 3 zijn afhankelijk of dit naar de linesensor gaat of niet.
proxSensors.initThreeSensors();
}


// Zorgt voor programma loop
void loop(){


//uitlezen van de prox sensor // 4 privates
proxSensors.read();

  //declaratie van de sensoren
  int FrontLeftSensor = proxSensors.countsFrontWithLeftLeds(); // tussen links en middelste sensor
  int FrontRightSensor = proxSensors.countsFrontWithRightLeds(); // tussen middelste en rechter sensor



//uitprinten van de sensoren en welke wat is.

Serial.print("Front Left: ");
Serial.print(FrontLeftSensor);
Serial.print(" ");
Serial.print("Front Right: ");
Serial.println(FrontRightSensor);

// een kleine delay (zorgt voor betere functionaliteit omdat het niet constant iets moet lezen des te langer des te beter)
delay(200);
}
