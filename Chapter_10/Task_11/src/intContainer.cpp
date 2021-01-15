#include "../inc/IntContainer.h"

#include <iostream>

IntContainer::IntContainer(int num)
{
    m_num = num;
}

void IntContainer::setNum(int num)
{
    m_num = num;
}

void IntContainer::print()
{
    std::cout << "Number: " << m_num << std::endl;
}