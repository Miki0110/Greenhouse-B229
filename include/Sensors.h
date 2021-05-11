#ifndef Sensors
#define Sensors

#include <string>
#include <time.h>
#include <Simulator.h>

;
//time_t timer;
std::string;

class Sensor //ParentClass
{
private:
    double Value = 0;
    double inputValue = 0;
    Simulator &the_connected_sim;

public:
    Sensor(Simulator &sim) : the_connected_sim(sim)
    {
        Value = 5; ///
    };
    double getValue() { return the_connected_sim.getValue(); };
    double getInputValue() { return inputValue; };
};

void getInputValue()
{
    // GUI.Sim.get
}

#endif //Sensors
