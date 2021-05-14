#pragma once

#include <string>
#include <time.h>
#include "Simulator.h"
#include "Sensors.h"

class WaterSensor : public BaseSensor
{
private:
    float measurementData;

public:
    //WaterSensor(Simulator &sim, std::string name) : the_connected_sim(sim), sensorName(name){};

    WaterSensor(Simulator &sim, std::string name) : BaseSensor(sim, name) {}

    float measure() override
    {
        return the_connected_sim.getWaterValue();
    };
    virtual float measurementConversion();
};