#include <string>
#include <time.h>
#include "Simulator.h"
#include "Sensors.h"

class WaterSensor : public BaseSensor
{
private:
    float Value = 0;
    float rawMeasurementData;
    Simulator &the_connected_sim;

public:
    float measure() override { return the_connected_sim.getWaterValue(); };
};