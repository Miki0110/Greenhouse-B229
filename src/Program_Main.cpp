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
std::string;
BaseControl Control;

int main(int argc, char const *argv[])
{
    //          (lightMax, lightMin, waterMax, waterMin)
    Plant Box1_Plant(1, 2, 3, 4);

    Box1_Plant.getWaterDesired(1);

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Greenhouse Simulator");
    window.setFramerateLimit(60);

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

        // draw everything here...
        //window.draw(my_tomato_view);

        // end the current frame
        window.display();

        //Calculate the running speed
        clock_t endTime = clock();
        clock_t clockTicksTaken = endTime - startTime;
        double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
    }

    return 0;
}

/*
lock_t startTime = clock();
doSomeOperation();
clock_t endTime = clock();
clock_t clockTicksTaken = endTime - startTime;
double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;

*/