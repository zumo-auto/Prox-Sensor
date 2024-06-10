#ifndef MY_ZUMO32U4_PROXIMITY_H
#define MY_ZUMO32U4_PROXIMITY_H

#include <Zumo32U4.h>

class MyZumo32U4Proximity {
public:
    MyZumo32U4Proximity();
    void setup();
    void loop();

private:
    Zumo32U4ProximitySensors proxSensors;
};

#endif
