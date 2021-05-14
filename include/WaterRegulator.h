#pragma once

#include <string>
#include <time.h>
#include "Simulator.h"
#include "Regulators.h"

class WaterRegulator : public BaseRegulator
{
private:
    float regulateData;

public:
    WaterRegulator(Simulator &sim, std::string name) : BaseRegulator(sim, name){};

    void regulate(float newWater) override { the_connected_sim.addWater(newWater); };
    //virtual float regulateConversion();
};