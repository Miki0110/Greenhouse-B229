#include <Sensors.h>
#include <Plants.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <time.h>
#include <SFML/Graphics.hpp>

//time_t timer;
std::string;

int main(int argc, char const *argv[])
{
    /* using namespace std::chrono_literals;
    int k = 5;

    std::this_thread::sleep_for(1s);
*/
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tomato Simulator");
    window.setFramerateLimit(60);

    sf::Clock deltaClock;

    while (window.isOpen())
    {
        clock_t startTime = clock();

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