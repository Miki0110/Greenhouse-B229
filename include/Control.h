#pragma once

#include <iostream>
#include <Sensors.h>
#include "LightSensor.h"
#include "WaterSensor.h"
#include "Simulator.h"
#include "Plants.h"
#include "Regulators.h"
#include "LightRegulator.h"
#include "WaterRegulator.h"

class BaseControl //ParentClass
{
protected:
    Plant &OurPlant;
    LightSensor SensorLight;
    WaterSensor SensorWater;
    LightRegulator RegulatorforLight;
    WaterRegulator RegulatorforWater;

public:
    BaseControl(Plant &plant, LightSensor SensL, WaterSensor SensW, LightRegulator RegL, WaterRegulator RegW) : OurPlant(plant), SensorLight(SensL), SensorWater(SensW), RegulatorforLight(RegL), RegulatorforWater(RegW){};
    //BaseSensor(Simulator &sim, std::string name) : the_connected_sim(sim), sensorName(name){};
    //BaseControl(Plant &plant) : OurPlant(plant){};

    void updateLight()
    {
        //Under Minimum
        if (OurPlant.getLightDesired(0) >= SensorLight.measure())
        {
            RegulatorforLight.regulate(1);
        }
        //Over Maximum
        if (OurPlant.getLightDesired(1) <= SensorLight.measure())
        {
            RegulatorforLight.regulate(0);
        }
    };
    void updateWater()
    {
        //Under Minimum
        if (OurPlant.getWaterDesired(0) > SensorWater.measure())
        {
            //Filling water from current pos, to max
            RegulatorforWater.regulate(OurPlant.getWaterDesired(1) - SensorWater.measure());
        }
        /*
        //Over Maximum
        if (OurPlant.getWaterDesired(1) < SensorWater.measure())
        {
            RegulatorforWater.regulate(0);
        }
        */
    };

    void UpdateValues()
    {
        updateLight();
        updateWater();
    };
};

/*
call sensors
Call plants
Compare sensordata with plants ideals
Calculate desired changes
Call regulator with new values
*/