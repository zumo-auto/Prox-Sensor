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


//uitlezen van de prox sensor
proxSensors.read()

  //declaratie van de sensoren
  int LeftSensor = proxSensors.countsLeftWithLeftLeds(); // linker sensor
  int FrontLeftSensor = proxSensors.countsFrontWithLeftLeds(); // tussen links en middelste sensor
  int FrontRightSensor = proxSensors.countsFrontWithRightLeds(); // tussen middelste en rechter sensor
  int RightSensor = proxSensors.countsRightWithRightsLeds(); // rechter sensor


//uitprinten van de sensoren en welke wat is.
Serial.print("Left: ");
Serial.print(leftSensor);
Serial.print(" ");
Serial.print("Front Left Sensor: ");
Serial.print(FrontLeftSensor);
Serial.print(" ");
Serial.print("Front Right Sensor: ");
Serial.print(frontRightSensor);
Serial.print(" ");
Serial.print("Right Sensor: ");
Serial.print(RightSensor);

// een kleine delay (zorgt voor betere functionaliteit omdat het niet constant iets moet lezen des te langer des te beter)
delay(200);
