#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <iostream>
#include <vector>
#include "Plant.h"

class Greenhouse
{
private:
    std::vector<Plant *> m_plants;

    double m_temperature;
    double m_humidity;
    CO2Level m_co2Level;
    Lighting m_lighting;

    const char *determineLighting(Lighting lighting) const;
    const char *determineCO2Level(CO2Level co2level) const;

    Plant *findPlant(Plant *plant);
    int findPlantIndex(Plant *Plant);

public:
    Greenhouse(double initTemp, double initHumidity = 0, CO2Level initCO2 = normal, Lighting initLighting = regular);

    void checkRequirements() const;

    void changeTemperature(double temp);
    void changeHumidity(double humidity);
    void changeLighting(Lighting lighting);
    void changeCO2Level(CO2Level co2level);

    void addPlant(Plant &plant);
    void removePlant(Plant &plant);
};

inline Greenhouse::Greenhouse(double initTemp, double initHumidity, CO2Level initCO2, Lighting initLighting)
    : m_temperature(initTemp),
      m_humidity(initHumidity),
      m_co2Level(initCO2),
      m_lighting(initLighting) {}

inline const char *Greenhouse::determineLighting(Lighting lighting) const
{
    switch (lighting)
    {
    case dim:
        return "dim";
    case regular:
        return "regular";
    case bright:
        return "bright";
    }

    return "";
}

inline const char *Greenhouse::determineCO2Level(CO2Level co2level) const
{
    switch (co2level)
    {
    case low:
        return "low";
    case normal:
        return "normal";
    case high:
        return "high";
    }

    return "";
}

inline void Greenhouse::checkRequirements() const
{
    std::cout << std::endl;

    for (auto it = m_plants.begin(); it != m_plants.end(); it++)
    {
        if ((*it)->m_minTemp > m_temperature)
        {
            std::cout << (*it)->identify()
                      << " requires a minimum temperature of "
                      << (*it)->m_minTemp
                      << "°C. The current temperature is "
                      << m_temperature
                      << "°C. Remove the plant or change the temperature."
                      << std::endl;
        }

        if ((*it)->m_maxTemp < m_temperature)
        {
            std::cout << (*it)->identify()
                      << " requires a maximum temperature of "
                      << (*it)->m_maxTemp
                      << "°C. The current temperature is "
                      << m_temperature
                      << "°C. Remove the plant or change the temperature."
                      << std::endl;
        }

        if ((*it)->m_minHumidity > m_humidity)
        {
            std::cout << (*it)->identify()
                      << " requires a minimum humidity of "
                      << (*it)->m_minHumidity
                      << "%. The current humidity is "
                      << m_humidity
                      << "%. Remove the plant or change the humidity."
                      << std::endl;
        }

        if ((*it)->m_maxHumidity < m_humidity)
        {
            std::cout << (*it)->identify()
                      << " requires a maximum humidity of "
                      << (*it)->m_maxHumidity
                      << "%. The current humidity is "
                      << m_humidity
                      << "%. Remove the plant or change the humidity."
                      << std::endl;
        }

        if ((*it)->m_perfectLighting != m_lighting)
        {
            std::cout << determineLighting((*it)->m_perfectLighting)
                      << " lighting is recommended for "
                      << (*it)->identify()
                      << ". The current lighting is "
                      << determineLighting(m_lighting)
                      << std::endl;
        }

        if ((*it)->m_perfectCO2Level != m_co2Level)
        {
            std::cout << determineCO2Level((*it)->m_perfectCO2Level)
                      << " CO2 level is recommended for "
                      << (*it)->identify()
                      << ". The current CO2 level is "
                      << determineCO2Level(m_co2Level)
                      << std::endl;
        }

        std::cout << std::endl;
    }
}

inline void Greenhouse::changeTemperature(double temp)
{
    if (m_temperature == temp)
    {
        std::cout << "Temperature is already set to " << m_temperature << "°C" << std::endl;
        return;
    }

    std::cout << (m_temperature > temp ? "Increasing " : "Decreasing ")
              << " temperature...\nNew temperature: ";

    m_temperature = temp;

    std::cout << m_temperature << "°C" << std::endl;
}

inline void Greenhouse::changeHumidity(double humidity)
{
    if (m_humidity == humidity)
    {
        std::cout << "Humidity is already set to " << m_humidity << "%" << std::endl;
        return;
    }

    if (humidity < 0 || humidity > 100)
    {
        std::cout << "The humidity must be between 0% and 100%" << std::endl;
    }

    std::cout << (m_humidity > humidity ? "Increasing " : "Decreasing ")
              << " humidity...\nNew humidity: ";

    m_humidity = humidity;

    std::cout << m_humidity << "%" << std::endl;
}

inline void Greenhouse::changeLighting(Lighting lighting)
{
    if (m_lighting == lighting)
    {
        std::cout << "Lighting is already set to " << determineLighting(m_lighting) << std::endl;
        return;
    }

    if (lighting < dim || lighting > bright)
    {
        std::cout << "Invalid level of brightness. It must be dim, regular or bright. " << std::endl;
    }

    std::cout << (m_lighting > lighting ? "Increasing " : "Decreasing ")
              << " lighting...\nNew lighting: ";

    m_lighting = lighting;

    std::cout << determineLighting(m_lighting) << std::endl;
}

inline void Greenhouse::changeCO2Level(CO2Level co2level)
{
    if (m_co2Level == co2level)
    {
        std::cout << "CO2 level is already set to " << determineCO2Level(m_co2Level) << std::endl;
        return;
    }

    if (co2level < low || co2level > high)
    {
        std::cout << "Invalid CO2 level. It must be low, normal or high. " << std::endl;
    }

    std::cout << (m_co2Level > co2level ? "Increasing " : "Decreasing ")
              << " CO2 level...\nNew CO2 level: ";

    m_co2Level = co2level;

    std::cout << determineCO2Level(m_co2Level) << std::endl;
}

inline Plant *Greenhouse::findPlant(Plant *plant)
{
    for (auto it = m_plants.begin(); it != m_plants.end(); it++)
    {
        if (*it == plant)
        {
            return *it;
        }
    }

    return 0;
}

inline int Greenhouse::findPlantIndex(Plant *plant)
{
    for (size_t i = 0; i < m_plants.size(); i++)
    {
        if (m_plants[i] == plant)
        {
            return i;
        }
    }

    return -1;
}

inline void Greenhouse::addPlant(Plant &plant)
{
    Plant *plantPtr = findPlant(&plant);

    if (plantPtr)
    {
        std::cout << plant.identify() << " is already added to this greenhouse." << std::endl;

        return;
    }

    m_plants.push_back(&plant);
}

inline void Greenhouse::removePlant(Plant &plant)
{
    int index = findPlantIndex(&plant);

    if (index == -1)
    {
        std::cout << plant.identify() << " is not in this greenhouse." << std::endl;

        return;
    }

    m_plants.erase(m_plants.begin() + index);
}

#endif // GREENHOUSE_H