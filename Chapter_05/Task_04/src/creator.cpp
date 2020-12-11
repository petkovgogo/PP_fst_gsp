#include <iostream>
#include <string>
#include "../inc/Creator.h"
#include "../inc/Robot.h"

Creator::Creator(std::string name)
{
    m_name = name;
}

Creator::~Creator() {}

std::string Creator::getName() const
{
    return m_name;
}

void Creator::introduceCreation(Robot *creation)
{
    std::cout << creation->getName() << " is my creation" << std::endl;
}