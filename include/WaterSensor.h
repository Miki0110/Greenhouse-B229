#ifndef WaterSensor
#define WaterSensor

#include <string>
#include <time.h>
#include <Sensors.h>

//time_t timer;
std::string;

class WaterSensor //UnderClass
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
    double getValue() { return the_connected_sim.getWaterValue(); };
    double getInputValue() { return inputValue; };
};

#endif //WaterSensor
