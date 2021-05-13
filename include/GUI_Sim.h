/*
#pragma once

#include <string>
#include <time.h>
#include "imgui.h"      // necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h
#include "imgui-SFML.h" // for ImGui::SFML::* functions and SFML-specific overloads

#include <SFML/Graphics/CircleShape.hpp>    // To Create Circles
#include <SFML/Graphics/RectangleShape.hpp> // To Create Rectangles
#include <SFML/Graphics/RenderWindow.hpp>   // To Create A Window
#include <SFML/System/Clock.hpp>            // To Maintain Time
#include <SFML/Window/Event.hpp>            // To Create A Event
#include <cmath>                            // Basic math (Maybe not nessesary)

//time_t timer;
std::string;

class GUI_Sim
{
private:
    int AccesseriesNumber = 0;

public:
};

void CreateSideBar(std::string name, double minValue, double maxValue, std::string Colorget)
{
    std::string name2 = name + "Counter";
    name = name + "Holder";

    sf::RectangleShape name{sf::Vector2f{50., (float)WorldHeight * 8 / 10}};
    name.setFillColor(sf::Color::Transparent);
    name.setOutlineColor(sf::Color(192, 192, 192));
    name.setOutlineThickness(1);
    name.setOrigin(name.getSize().x / 2, name.getSize().y / 2);
    name.setPosition((WorldLength / 2) + ((WorldLength / 2) / (AccesseriesNumber + 1)), (float)WorldHeight / 2);

    sf::RectangleShape name2{name.getSize()};
    name2.setFillColor(sf::Color::Colorget);
    name2.setOutlineColor(name.getOutlineColor());
    name2.setOutlineThickness(name.getOutlineThickness());
    name2.setOrigin(name.getOrigin());
    name2.setPosition(name.getPosition());
    name2.rotate(180);
}
*/