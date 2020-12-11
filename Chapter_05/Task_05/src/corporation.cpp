#include <iostream>
#include "../inc/Creator.h"
#include "../inc/Corporation.h"

void Corporation::authenticate(Creator &employee)
{
    std::cout << "Wellcome, employee " << employee.m_name << std::endl;
}