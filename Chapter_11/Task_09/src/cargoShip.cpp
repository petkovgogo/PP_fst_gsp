#include "../inc/CargoShip.h"

#include <iostream>

CargoShip::CargoShip(int capacity, int cargo) : m_capacity(capacity), m_cargo(cargo) {}

void CargoShip::load(int cargo)
{
    std::cout << "Loading cargo..." << std::endl;

    if (m_cargo + cargo > m_capacity)
    {
        std::cout << "Cannot load cargo - max capacity reached" << std::endl;
    }
    else
    {
        m_cargo += cargo;
        std::cout << "Done." << std::endl;
    }
}

void CargoShip::unload(int cargo)
{
    std::cout << "Unloading cargo..." << std::endl;

    if (m_cargo - cargo < 0)
    {
        std::cout << "Unloaded all cargo" << std::endl;
        m_cargo = 0;
    }
    else
    {
        m_cargo -= cargo;
        std::cout << "Done." << std::endl;
    }
}

void CargoShip::sail() const
{
    std::cout << "Traveling to next harbour..." << std::endl;
    std::cout << "Done.\n" << std::endl;
}

void CargoShip::printCurrentLoad() const
{
    std::cout << "Current load: " << m_cargo << " t" << std::endl;
}
