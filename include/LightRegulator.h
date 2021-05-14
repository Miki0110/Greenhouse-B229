#pragma once

#include <string>
#include <time.h>
#include "Simulator.h"
#include "Regulators.h"

class LightRegulator : public BaseRegulator
{
private:
    float regulateData;

public:
    LightRegulator(Simulator &sim, std::string name) : BaseRegulator(sim, name){};

    void regulate(float LampState) override { the_connected_sim.setLampValue((bool)LampState); };
    //virtual float regulateConversion();
};