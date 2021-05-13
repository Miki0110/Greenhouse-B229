#include <string>
#include <time.h>
#include "Simulator.h"

class BaseRegulator //ParentClass
{
private:
    std::string regulatorName;

public:
    BaseRegulator(Simulator &sim, std::string name) : the_connected_sim(sim), regulatorName(name){};

    virtual void regulate(float);
    //void regulate(double newWater) override {&the_connected_sim.addWater(newWater)};
    //void regulate(bool LampState) override {&the_connected_sim.LampValue(LampState)};
protected:
    Simulator &the_connected_sim;
};