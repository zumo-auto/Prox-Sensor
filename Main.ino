#include "MyZumo32U4Proximity.h"

MyZumo32U4Proximity myProximitySensor;

void setup() {
    myProximitySensor.begin(); // Call the begin() method instead of setup()
}

void loop() {
    myProximitySensor.readSensors(); // Call the readSensors() method instead of loop()
    // Do other tasks or actions based on sensor readings
}
