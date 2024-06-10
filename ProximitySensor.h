#ifndef PROXIMITY_SENSOR_H
#define PROXIMITY_SENSOR_H

// Class to handle a generic proximity sensor
class ProximitySensor {
public:
    // Constructor to initialize sensor with given pins
    ProximitySensor(int leftPin, int rightPin);

    // Initialize the sensor pins
    void init();

    // Read the value from the left sensor
    int readLeft();

    // Read the value from the right sensor
    int readRight();

private:
    int leftPin;  // Pin connected to the left sensor
    int rightPin; // Pin connected to the right sensor
};

#endif // PROXIMITY_SENSOR_H
