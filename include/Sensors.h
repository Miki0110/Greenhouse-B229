#pragma once

#include <string>
#include <time.h>
#include "Simulator.h"

class BaseSensor //ParentClass
{
public:
    BaseSensor(Simulator &sim, std::string name) : the_connected_sim(sim), sensorName(name){};

    virtual float measure();
    std::string sensorName;
    Simulator &the_connected_sim;

    //protected:
};