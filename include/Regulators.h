#pragma once

#include <string>
#include <time.h>
#include "Simulator.h"

class BaseRegulator //ParentClass
{

public:
    BaseRegulator(Simulator &sim, std::string name) : the_connected_sim(sim), regulatorName(name){};

    virtual void regulate(float){};

protected:
    std::string regulatorName;
    Simulator &the_connected_sim;
};