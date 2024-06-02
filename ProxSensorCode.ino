#include <Zumo32U4.h>

Zumo32U4ProximitySensors proxSensors;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;

// Setup functie die voor voornamelijk voor de instellingen voor de loop zorgen.

void setup(){
  // the bit rate (snelheid van communicatie) zetten wat 9600 (standaard) zal zijn 
  Serial.begin(9600);

    Serial.println("Press Button A to start...");
    while (!buttonA.getSingleDebouncedPress()){
      // hij wacht hier totdat buttonA is ingedrukt en losgelaten.
    }

  Serial.printLn("Button A pressed, starting....");

//prox sensor initializeren  - Dit kan eventueel naar 2 of 3 zijn afhankelijk of dit naar de linesensor gaat of niet.
proxSensors.initThreeSensors();
}


// Zorgt voor programma loop
void loop(){
if (buttonB.getSingleDebouncedPress()){
  Serial.println("Button B pressed, stopping...");
  while (true){
    // stopt de programma als button B is gedrukt (infinite loop) - DUS HIJ BLIJFT TECHNISCH GEZIEN AAN!!
  }
}
  



//uitlezen van de prox sensor
proxSensors.read();

  //declaratie van de sensoren
  int LeftSensor = proxSensors.countsLeftWithLeftLeds(); // linker sensor
  int FrontLeftSensor = proxSensors.countsFrontWithLeftLeds(); // tussen links en middelste sensor
  int FrontRightSensor = proxSensors.countsFrontWithRightLeds(); // tussen middelste en rechter sensor
  int RightSensor = proxSensors.countsRightWithRightLeds(); // rechter sensor


//uitprinten van de sensoren en welke wat is.
Serial.print("Left: ");
Serial.print(LeftSensor);
Serial.print(" ");
Serial.print("Front Left Sensor: ");
Serial.print(FrontLeftSensor);
Serial.print(" ");
Serial.print("Front Right Sensor: ");
Serial.print(FrontRightSensor);
Serial.print(" ");
Serial.print("Right Sensor: ");
Serial.print(RightSensor);

// een kleine delay (zorgt voor betere functionaliteit omdat het niet constant iets moet lezen des te langer des te beter)
delay(200);
}
