#include <string>
#include <time.h>
#include "Simulator.h"
#include "Regulators.h"

class WaterRegulator : public BaseRegulator
{
private:
    float regulateData;

public:
    void regulate(float newWater) override { the_connected_sim.addWater(newWater); };
    virtual float regulateConversion();
};