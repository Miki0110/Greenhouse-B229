#include <string>
#include <time.h>
#include "Simulator.h"
#include "Sensors.h"

class WaterRegulator : public BaseSensor
{
private:
    double Value = 0;
    double rawMeasurementData;
    Simulator & the_connected_sim;

public:
    double measure() override { return the_connected_sim.getWaterValue(); };
   
    //void regulate(double newWater) override {&the_connected_sim.addWater(newWater)};
};