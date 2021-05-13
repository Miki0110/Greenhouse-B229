#pragma once

#include <string>
#include <time.h>

class Plant
{
private:
    std::string plantName;
    int lightDesired[2] = {0, 0};
    int waterDesired[2] = {0, 0};
    int humidityDirtDesired[2] = {0, 0};
    int humidityAirDesired[2] = {0, 0};
    int pHDesired[2] = {0, 0};
    int temperatureDesired[2] = {0, 0};

public:
    Plant(int lightMax, int lightMin, int waterMax, int waterMin)
    {
        lightDesired[0] = lightMin;
        lightDesired[1] = lightMax;
        waterDesired[0] = waterMin;
        waterDesired[1] = waterMax;
    };
    int getLightDesired(int i) { return lightDesired[i]; };
    int getWaterDesired(int i) { return waterDesired[i]; };
    int getHumidityDirtDesired(int i) { return humidityDirtDesired[i]; };
    int getHumidityAirDesired(int i) { return humidityAirDesired[i]; };
    int getpHDesired(int i) { return pHDesired[i]; };
    int getTemeratureDesired(int i) { return temperatureDesired[i]; };
};
