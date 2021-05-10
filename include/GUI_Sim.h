#ifndef GUI_Sim
#define GUI_Sim

#include <string>
#include <time.h>

//time_t timer;
std::string;

class GUI_Sim
{
private:
public:
};

void CreateSideBar(string name, double minValue, double maxValue, string Color)
{

    sf::RectangleShape WaterLevelHolder{sf::Vector2f{50., (float)WorldHeight * 8 / 10}};
    WaterLevelHolder.setFillColor(sf::Color::Transparent);
    WaterLevelHolder.setOutlineColor(sf::Color(192, 192, 192));
    WaterLevelHolder.setOutlineThickness(1);
    WaterLevelHolder.setOrigin(WaterLevelHolder.getSize().x / 2, WaterLevelHolder.getSize().y / 2);
    WaterLevelHolder.setPosition((WorldLength / 2) + ((WorldLength / 2) / (AccesseriesNumber + 1)), (float)WorldHeight / 2);
}

#endif //GUI_Sim
