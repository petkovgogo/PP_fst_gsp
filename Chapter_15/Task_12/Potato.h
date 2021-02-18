#ifndef POTATO_H
#define POTATO_H

#include "Plant.h"

class Potato : public Plant
{
public:
    Potato(double minTemp, double maxTemp, double minHumidity, double maxHumidity, Lighting l, CO2Level co2);

    const char*identify();
};

inline Potato::Potato(double minTemp, double maxTemp, double minHumidity, double maxHumidity, Lighting l, CO2Level co2)
    : Plant(minTemp, maxTemp, minHumidity, maxHumidity, l, co2) {}

inline const char*Potato::identify() { return "Potato"; }

#endif // POTATO_H