#include <iostream>
#include "../inc/DynamicDouble.h"

DynamicDouble::DynamicDouble(double num) : m_num(new double(num)) {}

#ifdef FIXED

DynamicDouble::DynamicDouble(DynamicDouble &original) : m_num(new double(*original.m_num)) {}

#endif // FIXED

DynamicDouble::~DynamicDouble()
{
    std::cout << "Using the destructor of DynamicDouble. Value: "
              << *m_num << std::endl;

    *m_num = -1;
    delete m_num;
    m_num = 0;
}

void DynamicDouble::print() const
{
    std::cout << "Value: " << *m_num << std::endl;
}