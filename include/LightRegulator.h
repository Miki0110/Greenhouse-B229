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
    //double measure() override { return the_connected_sim.getLampValue(); };

    void regulate(float LampState) override { the_connected_sim.setLampValue((bool)LampState); };
    virtual float regulateConversion();
};