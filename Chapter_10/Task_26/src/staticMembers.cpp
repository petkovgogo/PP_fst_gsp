#include "../inc/StaticMembers.h"

#include <iostream>

double StaticMembers::m_dNum = 3.14;
long StaticMembers::m_lNum = 1000000000000L;

void StaticMembers::printValues()
{
    std::cout
        << "Double: "
        << m_dNum
        << "\nLong: "
        << m_lNum
        << std::endl;
}