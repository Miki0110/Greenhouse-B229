#include <string>
#include <time.h>
#include "Simulator.h"

class BaseSensor //ParentClass
{
private:
    std::string sensorName;

public:
    BaseSensor(Simulator &sim, std::string name) : the_connected_sim(sim), sensorName(name){};

    virtual float measure();

protected:
    Simulator &the_connected_sim;
};