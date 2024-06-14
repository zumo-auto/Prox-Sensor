#include "MyZumo32U4Proximity.h"
#include <Arduino.h>

MyZumo32U4Proximity::MyZumo32U4Proximity() {
    // Constructor
}

void MyZumo32U4Proximity::begin() {
    Serial.begin(9600); // Set the bit rate for communication
    proxSensors.initThreeSensors(); // Initialize proximity sensors
}

void MyZumo32U4Proximity::readSensors() {
    proxSensors.read(); // Read proximity sensors
    frontLeftSensorValue = proxSensors.countsFrontWithLeftLeds();
    frontRightSensorValue = proxSensors.countsFrontWithRightLeds();

    Serial.print("Front Left: ");
    Serial.print(frontLeftSensorValue);
    Serial.print(" ");
    Serial.print("Front Right: ");
    Serial.println(frontRightSensorValue);
    delay(200);
}

int MyZumo32U4Proximity::getFrontLeftSensorValue() {
    return frontLeftSensorValue;
}

int MyZumo32U4Proximity::getFrontRightSensorValue() {
    return frontRightSensorValue;
}
