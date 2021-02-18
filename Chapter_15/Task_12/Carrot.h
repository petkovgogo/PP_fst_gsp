#ifndef CARROT_H
#define CARROT_H

#include "Plant.h"

class Carrot : public Plant
{
public:
    Carrot(double minTemp, double maxTemp, double minHumidity, double maxHumidity, Lighting l, CO2Level co2);

    const char*identify();
};

inline Carrot::Carrot(double minTemp, double maxTemp, double minHumidity, double maxHumidity, Lighting l, CO2Level co2)
    : Plant(minTemp, maxTemp, minHumidity, maxHumidity, l, co2) {}

inline const char*Carrot::identify() { return "Carrot"; }

#endif // CARROT_H