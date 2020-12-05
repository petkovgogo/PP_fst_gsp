#include <iostream>
#include "../inc/Robot.h"

Robot::Robot(std::string name, Battery &battery)
{
    m_name = name;
    m_battery = &battery;
}

Robot::Battery::Battery(std::string type, int capacity)
{
    m_type = type;
    m_capacity = capacity;
}

void Robot::Battery::charge()
{
    std::cout << "Charging..." << std::endl;
}

void Robot::Battery::printDetails()
{
    std::cout <<
        "Type: " << m_type << std::endl << 
        "Capacity: " << m_capacity << std::endl;
    
}

void Robot::greeting()
{
    std::cout << "Hello fellow human :]! I am " << m_name << std::endl;
}

void Robot::beep()
{
    std::cout << "beep-boop" << std::endl;
}