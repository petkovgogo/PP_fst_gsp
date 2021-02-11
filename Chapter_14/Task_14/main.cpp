#include <iostream>
#include "BusinessTraveler.h"

#define PRINT(VAR) \
    std::cout << #VAR ":\n" << VAR << std::endl;

int main()
{
    std::cout << "Using constructor:" << std::endl;
    BusinessTraveler traveler1("John");

    PRINT(traveler1)

    std::cout << "\nUsing copy-constructor:" << std::endl;
    BusinessTraveler traveler2(traveler1);

    PRINT(traveler2)

    std::cout << "\nUsing default constructor and BusinessTraveler::operator=():" << std::endl;
    BusinessTraveler traveler3;

    PRINT(traveler3)
    PRINT((traveler3 = traveler2))

    return 0;
}