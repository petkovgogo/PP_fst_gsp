#include "../inc/Integer.h"

#include <iostream>

Integer::Integer(int num)
{
    m_num = num;
}

void Integer::print()
{
    std::cout << "Number: " << m_num << std::endl;
}