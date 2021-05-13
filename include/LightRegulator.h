#include <string>
#include <time.h>
#include "Simulator.h"
#include "Regulators.h"

class LightRegulator : public BaseRegulator
{
private:
    //    Simulator &the_connected_sim;

public:
    //double measure() override { return the_connected_sim.getLampValue(); };

    void regulate(float LampState) override { &the_connected_sim.setLampValue(LampState); };
};