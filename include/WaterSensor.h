#include <string>
#include <time.h>
#include "Simulator.h"
#include "Sensors.h"

class WaterSensor : public BaseSensor
{
private:
    float measurementData;

public:
    float measure() override { return the_connected_sim.getWaterValue(); };
    virtual float measurementConversion();
};