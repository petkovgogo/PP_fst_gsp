#ifndef TOMATO_H
#define TOMATO_H

#include "Plant.h"

class Tomato : public Plant
{
public:
    Tomato(double minTemp, double maxTemp, double minHumidity, double maxHumidity, Lighting l, CO2Level co2);

    const char*identify();
};

inline Tomato::Tomato(double minTemp, double maxTemp, double minHumidity, double maxHumidity, Lighting l, CO2Level co2)
    : Plant(minTemp, maxTemp, minHumidity, maxHumidity, l, co2) {}

inline const char*Tomato::identify() { return "Tomato"; }

#endif // TOMATO_H