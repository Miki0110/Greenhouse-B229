#pragma once

#include <string>
#include <time.h>
//#include <Sensors.h>

class Simulator //Class
{
private:
    double currentTime = 0;
    float WaterValue = 0;
    bool LampValue = 0;
    float TotalLightHours = 0;

    float WaterValueChange = 0;
    float TotalLightHourschange = 1;

    //Simulator& the_connected_sim;

public:
    float getWaterValue() { return WaterValue; };
    void addWater(float &newWater) { WaterValue = +newWater; };
    bool getLampValue() { return LampValue; };
    void setLampValue(bool i) { LampValue = i; };
    bool getTimeValue() { return currentTime; };
    float getTotalLightValue() { return TotalLightHours; };

    void SetTime(int hour, int min)
    {
        currentTime = currentTime + hour + (min / 60);
    };

    void SimulateTime(int HourGot)
    {
        //Call to regulator

        WaterValue = WaterValue + (WaterValueChange * HourGot);
        TotalLightHours = TotalLightHours + (TotalLightHourschange * HourGot);

        if (LampValue)
        {
            TotalLightHours = TotalLightHours + (TotalLightHourschange * HourGot);
        };
    };
};

//#endif //Simulator