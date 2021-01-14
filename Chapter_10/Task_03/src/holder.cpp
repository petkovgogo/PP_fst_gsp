#include <iostream>
#include "../inc/Holder.h"

int Holder::m_num = 42;

void Holder::printStatic()
{
    std::cout << "\nStatic member value: " << m_num << std::endl;
}