#include <string>
#include <time.h>
#include "Simulator.h"
#include "Sensors.h"

class LampRegulator : public BaseSensor
{
private:
    double Value = 0;
    double rawMeasurementData;
    Simulator &the_connected_sim;

public:
    double measure() override { return the_connected_sim.getLampValue(); };

    //void regulate(bool LampState) override {&the_connected_sim.LampValue(LampState)};
};