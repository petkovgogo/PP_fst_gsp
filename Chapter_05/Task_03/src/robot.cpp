#include <iostream>
#include "../inc/Robot.h"

Robot::Robot(std::string name)
{
    m_name = name;
}

Robot::~Robot() {}

void greeting(Robot &robot)
{
    std::cout << "Hello! I am " << robot.m_name << std::endl;
}