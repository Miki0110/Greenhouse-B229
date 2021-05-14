#pragma once

#include <string>
#include <time.h>
#include "Simulator.h"
#include "Sensors.h"

class LightSensor : public BaseSensor
{
private:
    float measurementData;

public:
    LightSensor(Simulator &sim, std::string name) : BaseSensor(sim, name) {}

    float measure() override { return the_connected_sim.getTotalLightValue(); };

    //virtual float measurementConversion();
};