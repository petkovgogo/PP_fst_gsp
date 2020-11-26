#include <iostream>
#include "../inc/Functions.h"

int main()
{
    printName("Gosho");
    std::cout << getChar('o') << std::endl;
    std::cout << sum(1, 2) << std::endl;
    std::cout << divide(5, 4) << std::endl;

    return 0;
}