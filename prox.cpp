#include "MyZumo32U4Proximity.h"
#include <Arduino.h>

MyZumo32U4Proximity::MyZumo32U4Proximity() {
    // Constructor
}

void MyZumo32U4Proximity::setup() {
    Serial1.begin(4800); // Set the bit rate for communication
    proxSensors.initThreeSensors(); // Initialize proximity sensors
}

void MyZumo32U4Proximity::loop() {
    proxSensors.read(); // Read proximity sensors

    // Read sensor values
    int FrontLeftSensor = proxSensors.countsFrontWithLeftLeds(); 
    int FrontRightSensor = proxSensors.countsFrontWithRightLeds(); 

    /* Print sensor values - De waardes zijn voornamelijk 0 - 3 - 6 
      0 betekent niks, 
      3-5 betekent dat het iets detecteert wat vrij ver kan zijn
      6 betekent dat het iets vlak voor zich detecteert
      naast deze waardes KAN het voorkomen dat als iets TE dichtbij is dat de waardes weer omlaag gaan.
      */
    Serial1.print("Front Left: ");
    Serial1.print(FrontLeftSensor);
    Serial1.print(" ");
    Serial1.print("Front Right: ");
    Serial1.println(FrontRightSensor);

    delay(200); // Small delay for better functionality
}
