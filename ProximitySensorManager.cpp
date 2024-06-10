#include "ProximitySensorManager.h"

// Constructor initializes the front sensor with specific pins
ProximitySensorManager::ProximitySensorManager() : frontSensor(A0, A1), leftSensorValue(0), rightSensorValue(0) {}

// Initialize all sensors
void ProximitySensorManager::init() {
    frontSensor.init(); // Initialize the front sensor
}

// Read values from all sensors
void ProximitySensorManager::readSensors() {
    leftSensorValue = frontSensor.readLeft();   // Read and store value from the left front sensor
    rightSensorValue = frontSensor.readRight(); // Read and store value from the right front sensor
}

// Get the value from the left front sensor
int ProximitySensorManager::getLeftSensorValue() {
    return leftSensorValue;
}

// Get the value from the right front sensor
int ProximitySensorManager::getRightSensorValue() {
    return rightSensorValue;
}
