#pragma once

#include <string>
#include <time.h>
//#include <Sensors.h>

class Simulator //Class
{
private:
    double currentTime = 0;
    double currentDay = 0;
    float WaterValue = 0;
    bool LampValue = 0;
    float TotalLightHours = 0;

    float WaterValueChange = -0.4;
    float TotalLightHourschange = 1;

    //Simulator& the_connected_sim;

public:
    float getWaterValue() { return WaterValue; };
    void addWater(float &newWater) { WaterValue = WaterValue + newWater; };
    bool getLampValue() { return LampValue; };
    void setLampValue(bool i) { LampValue = i; };
    float getTimeValue() { return currentTime; };
    float getDayValue() { return currentDay; };
    float getTotalLightValue() { return TotalLightHours; };

    void SetTime(int hour, int min)
    {
        currentTime = currentTime + hour + (min / 60);
    };

    void SimulateTime(int HourGot)
    {
        currentTime = currentTime + HourGot;
        if (currentTime > 24)
        {
            currentTime = currentTime - 24;
            currentDay++;
            TotalLightHours = 0;
        };
        //Call to regulator

        WaterValue = WaterValue + (WaterValueChange * HourGot);
        //TotalLightHours = TotalLightHours + (TotalLightHourschange * HourGot);

        if (LampValue)
        {
            TotalLightHours = TotalLightHours + (TotalLightHourschange * HourGot);
        }
    };
};

//#endif //Simulator