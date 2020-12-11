#include <iostream>
#include <string>
#include "../inc/Robot.h"
#include "../inc/Creator.h"

Robot::Robot(std::string name)
{
    m_name = name;
}

Robot::~Robot() {}

std::string Robot::getName() const
{
    return m_name;
}

void Robot::introduceCreator(Creator *creator)
{
    std::cout << "My creator is " << creator->m_name << std::endl; // friend class can access private members
}