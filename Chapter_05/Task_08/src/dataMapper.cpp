#include <iostream>
#include "../inc/DataMapper.h"

#define PRINT_ADDRESS(VAR) \
    std::cout << #VAR " -> " << (long)VAR << std::endl;

void DataMapper::showMap()
{
    std::cout << "\nPrivate: " << std::endl;
    PRINT_ADDRESS(&m_privIntVar);
    PRINT_ADDRESS(&m_privDoubleVar);

    std::cout << "\nProtected: " << std::endl;
    PRINT_ADDRESS(&m_protCharVar);
    PRINT_ADDRESS(&m_protBoolVar);

    std::cout << "\nPublic: " << std::endl;
    PRINT_ADDRESS(&m_pubFloatVar);
    PRINT_ADDRESS(&m_pubLongVar);
}