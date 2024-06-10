#ifndef PROXIMITY_SENSOR_MANAGER_H
#define PROXIMITY_SENSOR_MANAGER_H

#include "ProximitySensor.h"

// Class to manage multiple proximity sensors
class ProximitySensorManager {
public:
    // Constructor
    ProximitySensorManager();

    // Initialize all sensors
    void init();

    // Read values from all sensors
    void readSensors();

    // Get the value from the left front sensor
    int getLeftSensorValue();

    // Get the value from the right front sensor
    int getRightSensorValue();

private:
    ProximitySensor frontSensor; // Front proximity sensor
    int leftSensorValue;         // Value from the left front sensor
    int rightSensorValue;        // Value from the right front sensor
};

#endif // PROXIMITY_SENSOR_MANAGER_H
