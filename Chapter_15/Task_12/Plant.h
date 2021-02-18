#ifndef PLANT_H
#define PLANT_H

enum Lighting
{
    dim,
    regular,
    bright
};

enum CO2Level
{
    low,
    normal,
    high
};

class Plant
{
private:
    double m_minTemp;
    double m_maxTemp;
    double m_minHumidity;
    double m_maxHumidity;
    Lighting m_perfectLighting;
    CO2Level m_perfectCO2Level;
    
public:
    Plant(double minTemp, double maxTemp, double minHumidity, double maxHumidity, Lighting l, CO2Level co2);
    virtual ~Plant() = 0;

    virtual const char*identify() = 0;

    friend class Greenhouse;
};

Plant::~Plant() {}

inline Plant::Plant(double minTemp, double maxTemp, double minHumidity, double maxHumidity, Lighting l, CO2Level co2)
    : m_minTemp(minTemp),
      m_maxTemp(maxTemp),
      m_minHumidity(minHumidity),
      m_maxHumidity(maxHumidity),
      m_perfectLighting(l),
      m_perfectCO2Level(co2) {}

#endif // PLANT_H