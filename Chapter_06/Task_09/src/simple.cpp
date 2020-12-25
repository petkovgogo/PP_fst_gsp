#include <iostream>
#include "../inc/Simple.h"

Simple::Simple(int number)
{
    m_number = number;
    std::cout << "I am created with the value " << m_number << std::endl;
}

Simple::~Simple()
{
    std::cout << "I still hold the value " << m_number << ", but my existance ends here" << std::endl;
}

void Simple::printNumber()
{
    std::cout << "The number I am holding is: " << m_number << std::endl;
}