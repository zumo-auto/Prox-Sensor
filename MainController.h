#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include "ProximitySensorManager.h"

// Main controller class to manage the setup and loop operations
class MainController {
public:
    // Constructor
    MainController();

    // Setup function to initialize components
    void setup();

    // Loop function to handle repeated operations
    void loop();

private:
    ProximitySensorManager sensorManager; // Manager for proximity sensors
};

#endif // MAIN_CONTROLLER_H
