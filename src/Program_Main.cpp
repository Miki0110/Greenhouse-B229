//#include "imgui.h"      // necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h
//#include "imgui-SFML.h" // for ImGui::SFML::* functions and SFML-specific overloads

#include <Sensors.h>
#include <Plants.h>
#include "Simulator.h"
#include <Control.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <time.h>
#include <SFML/Graphics.hpp>

//time_t timer;
std::string boxnr = "Box 1";

//TESTING FROM IMGUIEXAMPLE

int WorldLength = 500;
int WorldHeight = 880;

int main(int argc, char const *argv[])
{
    //          (lightMax, lightMin, waterMax, waterMin)
    Plant Box1_Plant(14, 2, 100, 25);
    Simulator Sim;
    LightSensor SensorLight(Sim, boxnr);
    WaterSensor SensorWater(Sim, boxnr);
    LightRegulator RegulatorforLight(Sim, boxnr);
    WaterRegulator RegulatorforWater(Sim, boxnr);
    BaseControl Control(Box1_Plant, SensorLight, SensorWater, RegulatorforLight, RegulatorforWater);

    Box1_Plant.getWaterDesired(1);
    Sim.SetTime(12, 00);

    // create the window
    sf::RenderWindow window(sf::VideoMode(WorldLength, WorldHeight), "Greenhouse Simulator");
    window.setFramerateLimit(30);

    //TESTING FROM IMGUIEXAMPLE
    int AccesseriesNumber = 2;
    sf::RectangleShape WaterLevelHolder{sf::Vector2f{50., (float)WorldHeight * 8 / 10}};
    WaterLevelHolder.setFillColor(sf::Color::Transparent);
    WaterLevelHolder.setOutlineColor(sf::Color(192, 192, 192));
    WaterLevelHolder.setOutlineThickness(1);
    WaterLevelHolder.setOrigin(WaterLevelHolder.getSize().x / 2, WaterLevelHolder.getSize().y / 2);
    WaterLevelHolder.setPosition((WorldLength / 2) + ((WorldLength / 2) / (AccesseriesNumber + 1)), (float)WorldHeight / 2);
    sf::RectangleShape WaterLevelCounter{WaterLevelHolder.getSize()};
    WaterLevelCounter.setFillColor(sf::Color::Blue);
    WaterLevelCounter.setOutlineColor(WaterLevelHolder.getOutlineColor());
    WaterLevelCounter.setOutlineThickness(WaterLevelHolder.getOutlineThickness());
    WaterLevelCounter.setOrigin(WaterLevelHolder.getOrigin());
    WaterLevelCounter.setPosition(WaterLevelHolder.getPosition());
    WaterLevelCounter.rotate(180);
    sf::RectangleShape SunLevelHolder{sf::Vector2f{50., (float)WorldHeight * 8 / 10}};
    SunLevelHolder.setFillColor(sf::Color::Transparent);
    SunLevelHolder.setOutlineColor(sf::Color(192, 192, 192));
    SunLevelHolder.setOutlineThickness(1);
    SunLevelHolder.setOrigin(SunLevelHolder.getSize().x / 2, SunLevelHolder.getSize().y / 2);
    SunLevelHolder.setPosition((WorldLength / 2) + ((WorldLength * 2 / 2) / (AccesseriesNumber + 1)), (float)WorldHeight / 2);
    sf::RectangleShape SunLevelCounter{SunLevelHolder.getSize()};
    SunLevelCounter.setFillColor(sf::Color::Yellow);
    SunLevelCounter.setOutlineColor(SunLevelHolder.getOutlineColor());
    SunLevelCounter.setOutlineThickness(SunLevelHolder.getOutlineThickness());
    SunLevelCounter.setOrigin(SunLevelHolder.getOrigin());
    SunLevelCounter.setPosition(SunLevelHolder.getPosition());
    SunLevelCounter.rotate(180);

    sf::Clock deltaClock;

    while (window.isOpen())
    {
        //Call Control
        //Call Simulation
        clock_t startTime = clock();

        /*
    Get values from sensors
    See if changes is needed
    Edit if nessesary
    */
        Control.UpdateValues();

        WaterLevelCounter.setSize(sf::Vector2f{WaterLevelCounter.getSize().x, WaterLevelHolder.getSize().y * Sim.getWaterValue() / 100});
        SunLevelCounter.setSize(sf::Vector2f{SunLevelCounter.getSize().x, SunLevelHolder.getSize().y * Sim.getTotalLightValue() / 24});

        // check all the window's events that were triggered since the last
        // iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear();
        //accesseries
        window.draw(WaterLevelCounter);
        window.draw(WaterLevelHolder);
        window.draw(SunLevelCounter);
        window.draw(SunLevelHolder);

        // end the current frame
        window.display();

        //Simulate 1 day
        Sim.SimulateTime(1);

        std::cout << "Day : " << Sim.getDayValue() << "\nl";
        std::cout << "Current Time is : " << Sim.getTimeValue() << "\nl";
        std::cout << "Light value is : " << Sim.getTotalLightValue() << "\nl";
        std::cout << "Water value is : " << Sim.getWaterValue() << "\nl \nl";
    }

    return 0;
}
