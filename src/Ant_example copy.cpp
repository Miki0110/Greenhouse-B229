#include <Testing.h>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

//time_t timer;
std::string;

float MaxSpeed = 2;
float steerStrength = 2;
float Angle;
float TargetAngle;
float position[2];
float TargetPosition[2];
float velocity;
float time;
float lasttime;
float deltaTime;

/*void HandleFood(){
    //If no food is choosed
    if(targetFood== null){
    //Get all food objects within the perception radius
    
    }
}*/

void update()
{
    lasttime = time;
    time_t(&time);
    deltaTime = difftime(time, lasttime);

    float DesiredAngle = (TargetAngle - Angle);
    float DesiredVelocity = (DesiredAngle * MaxSpeed);
    float DesiredSteeringForce = (DesiredVelocity - velocity) * steerStrength;
    float Acceleration = (DesiredVelocity * velocity) / 1;

    velocity = ((velocity + Acceleration * deltaTime) * MaxSpeed);
    position[1] = cos(Angle) * velocity * deltaTime;
    position[2] = sin(Angle) * velocity * deltaTime;

    //Normalizing the velocity vector is velocity/speed, or velocity/sqrt(dot(velocity, velocity))
    //sqrt(dot(velocity, velocity)) is speed
    //dot(velocity,velocity) is speed_squared
}

int main(int argc, char const *argv[])
{
    int k = 5;
    return 0;
    cout << "Output sentence";
}