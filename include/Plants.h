#ifndef Plants
#define Plants

#include <string>
#include <time.h>

//time_t timer;
std::string;

class Plant
{
private:
    double height = 0.;
    int Num_Fruits = 0;
    double growth_rate = 0.;
    float Water_importance = 1.;
    float Sun_importance = 1.;
    float DirtHumindity_importance = 1.;

public:
    double getHeight() { return height; };
    int getNumFruits() { return Num_Fruits; };
    int getGrowth_rate() { return growth_rate; };

    void grow(int tics);
};

Plant::grow(int tics)
{
    height = height + tics * growth_rate;
}

#endif //Plants
