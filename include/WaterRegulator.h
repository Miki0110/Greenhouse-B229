#include <string>
#include <time.h>
#include "Simulator.h"
#include "Regulators.h"

class WaterRegulator : public BaseRegulator
{
private:
    Simulator &the_connected_sim;
    
public:
    //double measure() override { return the_connected_sim.getWaterValue(); };
   
    void regulate(float newWater) override {&the_connected_sim.addWater(newWater);};
};