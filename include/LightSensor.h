#include <string>
#include <time.h>
#include "Simulator.h"
#include "Sensors.h"

class LightSensor : public BaseSensor
{
private:
    float measurementData;

public:
    float measure() override { return the_connected_sim.getTotalLightValue(); };
    virtual float measurementConversion();
};