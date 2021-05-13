
#include <string>
#include <time.h>

class Plant
{
private:
    double lightIdeal = 0;
    double waterIdeal = 0;
    double humidityDirtIdeal = 0;
    double humidityAirIdeal = 0;
    double pHIdeal = 0;
    double temperatureIdeal = 0;

public:
    double getLightIdeal() { return lightIdeal; };
    double getWaterIdeal() { return waterIdeal; };
    double getHumidityDirtIdeal() { return humidityDirtIdeal; };
    double getHumidityAirIdeal() { return humidityAirIdeal; };
    double getpHIdeal() { return pHIdeal; };
    double getTemeratureIdeal() { return temperatureIdeal; };
};