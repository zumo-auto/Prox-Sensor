#include "ProximitySensor.h"
#include <Arduino.h>

// Constructor to initialize sensor pins
ProximitySensor::ProximitySensor(int leftPin, int rightPin) : leftPin(leftPin), rightPin(rightPin) {}

// Initialize the sensor pins
void ProximitySensor::init() {
    pinMode(leftPin, INPUT);  // Set left pin as input
    pinMode(rightPin, INPUT); // Set right pin as input
}

// Read the value from the left sensor
int ProximitySensor::readLeft() {
    return analogRead(leftPin); // Read and return analog value from left pin
}

// Read the value from the right sensor
int ProximitySensor::readRight() {
    return analogRead(rightPin); // Read and return analog value from right pin
}
