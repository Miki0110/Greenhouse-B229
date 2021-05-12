
#include <string>
#include <time.h>

class Plant
{
private:
    std::string plantName;
    int lightIdeal[2] = {0, 0};
    int waterIdeal[2] = {0, 0};
    int humidityDirtIdeal[2] = {0, 0};
    int humidityAirIdeal[2] = {0, 0};
    int pHIdeal[2] = {0, 0};
    int temperatureIdeal[2] = {0, 0};

public:
    Plant(int lightMax, int lightMin, int waterMax, int waterMin)
    {
        lightIdeal[0] = lightMin;
        lightIdeal[1] = lightMax;
        waterIdeal[0] = waterMin;
        waterIdeal[1] = waterMax;
    };
    int getLightIdeal(int i) { return lightIdeal[i]; };
    int getWaterIdeal(int i) { return waterIdeal[i]; };
    int getHumidityDirtIdeal(int i) { return humidityDirtIdeal[i]; };
    int getHumidityAirIdeal(int i) { return humidityAirIdeal[i]; };
    int getpHIdeal(int i) { return pHIdeal[i]; };
    int getTemeratureIdeal(int i) { return temperatureIdeal[i]; };
};
