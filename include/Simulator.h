//#ifndef Simulator
//#define Simulator

#include <string>
#include <time.h>
#include <Sensors.h>

//time_t timer;
std::string;
/*
1 døgn svarer til 360 grader
derfor
1 t     = 360/24 grader
1 min   = 360/1440 grader
1 sek   = 360/86400 grader
*/

class Simulator //Class
{
private:
    double Value = 0;
    double WaterValue = 0;
    double TemperatureValue = 0;
    double TemperatureAcceleration = 0;
    double HumidityDirtValue = 0;
    double HumidityAirValue = 0;
    double pHValue = 0;
    bool LampValue = 0;
    //Simulator& the_connected_sim;

public:
    double getValue() { return Value; };
    double getWaterValue() { return WaterValue; };
    double getTemperatureValue() { return TemperatureValue; };
    double getHumidityDirtValue() { return HumidityDirtValue; };
    double getHumidityAirValue() { return HumidityAirValue; };
    double getpHValue() { return pHValue; };
    bool getLampValue() { return LampValue; };

    void SetTime(int hour, int min){
        TemperatureAcceleration = cos((hour * 60) + (min))};

    void SimulateTimeSec(int Seconds){
        double current_time = acos(TemperatureAcceleration)
            TemperatureValue =

    };
};

//#endif //Simulator
