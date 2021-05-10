#ifndef Simulator
#define Simulator

#include <string>
#include <time.h>
#include <Sensors.h>

//time_t timer;
std::string;

class Simulator //Class
{
private:
    double Value = 0;
    double inputValue = 0;
    //Simulator& the_connected_sim;

public:
    /*Sensor(Simulator& sim) : the_connected_sim(sim) {
        Value = 5;///
    };*/
    double getValue() { return the_connected_sim.getTemperatureValue(); };
    double getInputValue() { return inputValue; };
};

#endif //Simulator
