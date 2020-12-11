#include <iostream>
#include <string>
#include "../inc/Creator.h"
#include "../inc/Robot.h"

Creator::Creator(std::string name)
{
    m_name = name;
}

Creator::~Creator() {}

void Creator::introduceCreation(Robot *creation)
{
    std::cout << creation->getName() << " is my creation" << std::endl;
}