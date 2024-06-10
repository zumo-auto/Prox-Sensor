#include "MainController.h"
#include <Arduino.h> // Ensure Arduino functions are available

// Constructor
MainController::MainController() {}

// Setup function to initialize components
void MainController::setup() {
    Serial1.begin(9600);      // Initialize Serial1 for communication at 9600 baud
    sensorManager.init();     // Initialize the sensor manager
}

// Loop function to handle repeated operations
void MainController::loop() {
    sensorManager.readSensors(); // Read values from sensors

    // Get sensor values
    int leftValue = sensorManager.getLeftSensorValue();
    int rightValue = sensorManager.getRightSensorValue();

    // Print sensor values to Serial1
    Serial1.print("Front Left: ");
    Serial1.print(leftValue);
    Serial1.print(" ");
    Serial1.print("Front Right: ");
    Serial1.println(rightValue);

    delay(200); // Small delay for better functionality
}
