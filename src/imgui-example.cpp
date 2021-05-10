#include "imgui.h" // necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h

#include "imgui-SFML.h" // for ImGui::SFML::* functions and SFML-specific overloads

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <cmath>

//Constants
//World Constants
float MoonTotalDegree = 0;
int ThisDay = 0;
int WorldLength = 1840;
int WorldHeight = 880;
float SimulationSpeed = 0.25;
float LightStrength;
const double pi = atan(1) * 4;

//The Plant
float ContainerLength = 200.;
float ContainerHeight = 200.;
sf::Vector2f ContainerPos = {(float)(WorldLength / 10) + ContainerLength, (float)(WorldHeight) - (ContainerHeight * 2 / 3)};
//sf::Vector2f CirclePos;

float MainBranchLength = 25.;
float MainBranchHeightMax = 500.;
int LeavesNumber = 12;
bool FlowerTrue = false;

//Affected variables
float WaterChange = -0.1;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WorldLength, WorldHeight), "Greenhouse");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    //Draw parts
    // Plant
    //Container
    sf::RectangleShape Container{sf::Vector2f{ContainerLength, ContainerHeight}};
    Container.setFillColor(sf::Color(165, 42, 42));
    Container.setOrigin(ContainerLength / 2, ContainerHeight / 2);
    Container.setPosition(ContainerPos);
    //Main body
    sf::RectangleShape MainBranch{sf::Vector2f{MainBranchLength, -0}};
    MainBranch.setFillColor(sf::Color::Green);
    MainBranch.setOrigin(MainBranchLength / 2, 0);
    MainBranch.setPosition(ContainerPos.x, ContainerPos.y - ContainerHeight / 2);
    MainBranch.rotate(180);
    //Top Flower
    sf::CircleShape TopFlower(100.f);
    TopFlower.setFillColor(sf::Color::Yellow);
    TopFlower.setPosition(200, 200);
    TopFlower.setOrigin(TopFlower.getRadius(), TopFlower.getRadius());
    //TopFlower.setPosition(MainBranch.getPosition().x, MainBranch.getPosition().y + MainBranchHeightMax);

    sf::CircleShape TopFlowerLeave(0.f);
    TopFlowerLeave.setFillColor(sf::Color::White);
    TopFlowerLeave.setOrigin(TopFlower.getRadius(), TopFlowerLeave.getRadius());
    TopFlowerLeave.setPosition(TopFlower.getPosition());
    TopFlowerLeave.setOutlineColor(sf::Color(150, 150, 150));
    TopFlowerLeave.setOutlineThickness(1);

    //World parameters
    //Sun
    sf::CircleShape Sun(50.f);
    Sun.setFillColor(sf::Color::Yellow);
    Sun.setOrigin(-WorldLength / 4, 50);
    Sun.setPosition(MainBranch.getPosition());
    Sun.rotate(180);
    //moon
    sf::CircleShape Moon(50.f);
    Moon.setFillColor(sf::Color(192, 192, 192));
    Moon.setOrigin(-WorldLength / 4, 50);
    Moon.setPosition(MainBranch.getPosition());
    sf::RectangleShape BlackBox{sf::Vector2f{(float)WorldLength / 1, (float)WorldHeight / 2}};
    BlackBox.setFillColor(sf::Color::Black);
    BlackBox.setOrigin(WorldLength / 2, 0);
    BlackBox.setPosition(MainBranch.getPosition());
    //accesseries
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

    /*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
    sf::Clock deltaClock;
    while (window.isOpen())
    {
        //Get the mouse position
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
        //Set the circle position to mouse position
        Sun.rotate(SimulationSpeed / 12);
        Moon.rotate(SimulationSpeed / 12);
        MoonTotalDegree = MoonTotalDegree + SimulationSpeed / 12;

        //Accesseries interactions
        if (WaterLevelCounter.getSize().y > 0)
        {
            WaterLevelCounter.setSize(WaterLevelCounter.getSize() + sf::Vector2f{0., WaterChange * SimulationSpeed / 12});
        }
        else
        {
            WaterLevelCounter.setSize(sf::Vector2f(WaterLevelCounter.getSize().x, 0.));
        }
        if (Sun.getRotation() > 180.)
        {
            LightStrength = 1;
            SunLevelCounter.setFillColor(Sun.getFillColor());
            SunLevelCounter.setSize(sf::Vector2f{SunLevelCounter.getSize().x, (float)(SunLevelHolder.getSize().y * ((-LightStrength) * sin(Sun.getRotation() * pi / 180.)))});
        }
        else if (Moon.getRotation() > 180.)
        {
            LightStrength = 0.12;
            SunLevelCounter.setFillColor(Moon.getFillColor());
            SunLevelCounter.setSize(sf::Vector2f{SunLevelCounter.getSize().x, (float)(SunLevelHolder.getSize().y * ((-LightStrength) * sin(Moon.getRotation() * pi / 180.)))});
        }
        else
        {
            SunLevelCounter.setSize(sf::Vector2f(SunLevelCounter.getSize().x, 0.));
        }
        /*PLANT GROW PART-----------------------------------------------------------------------------------------*/
        if (MainBranch.getSize().y < MainBranchHeightMax && MainBranch.getSize().y >= 0)
        {
            MainBranch.setSize(sf::Vector2f{MainBranch.getSize().x, (float)(MainBranch.getSize().y + ((WaterLevelCounter.getSize().y * 0.0005) * (SunLevelCounter.getSize().y * 0.0025)) * SimulationSpeed / 50)});
        }
        else if (MainBranch.getSize().y >= 0)
        {
            FlowerTrue = true;
            if (TopFlower.getRadius() < 200 && TopFlower.getRadius() >= 0)
            {
                TopFlower.setRadius((TopFlower.getRadius() + ((WaterLevelCounter.getSize().y * 0.0005) * (SunLevelCounter.getSize().y * 0.0025)) * SimulationSpeed / 50));
                TopFlower.setOrigin(TopFlower.getRadius(), TopFlower.getRadius());
                TopFlower.setPosition(MainBranch.getPosition().x, MainBranch.getPosition().y - MainBranchHeightMax);
                TopFlowerLeave.setRadius(TopFlower.getRadius() * pi / LeavesNumber);
                TopFlowerLeave.setOrigin(TopFlower.getRadius() + TopFlowerLeave.getRadius(), TopFlowerLeave.getRadius());
                TopFlowerLeave.setPosition(TopFlower.getPosition());
            }
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        //ImGui::ShowDemoWindow();
        //GUI----------------------------------------------------------------------------------------------------------
        ImGui::Begin("Hello, User!");
        ImGui::Text("Change Speed:");
        if (ImGui::Button("1 Hour"))
        {
            SimulationSpeed = 1.;
        };
        ImGui::SameLine();
        if (ImGui::Button("1 day"))
        {
            SimulationSpeed = 24;
        };
        ImGui::SameLine();
        if (ImGui::Button("1 month"))
        {
            SimulationSpeed = 24 * 60;
        };
        ImGui::SameLine();
        if (ImGui::Button("1,5 month"))
        {
            SimulationSpeed = 1080;
        };
        ImGui::SliderFloat("Time Speed", &SimulationSpeed, 0., 100.);
        ImGui::Text("Accesseries:");
        if (ImGui::Button("Fill Water"))
        {
            WaterLevelCounter.setSize(WaterLevelHolder.getSize());
        }
        ThisDay = floor((90 + MoonTotalDegree) / 360);
        ImGui::Value("This is day nr : ", ThisDay);

        ImGui::End();

        window.clear();
        //Background
        window.draw(Sun);
        window.draw(Moon);
        window.draw(BlackBox);
        //Plant
        window.draw(Container);
        window.draw(MainBranch);
        if (FlowerTrue)
        {
            for (int i = 0; i = LeavesNumber; i++)
            {
                window.draw(TopFlowerLeave);
                TopFlowerLeave.rotate(360 / LeavesNumber);
                //window.draw(TopFlowerLeave);
            };
            window.draw(TopFlower);
        };
        //accesseries
        window.draw(WaterLevelCounter);
        window.draw(WaterLevelHolder);
        window.draw(SunLevelCounter);
        window.draw(SunLevelHolder);

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0; //all
}
