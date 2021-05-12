#include <string>
#include <time.h>
#include "Simulator.h"
#include "Regulators.h"

class LampRegulator : public BaseRegulator
{
private:

public:
    //double measure() override { return the_connected_sim.getLampValue(); };

    void regulate(float LampState) override {&the_connected_sim.setLampValue((bool)LampState);};
};