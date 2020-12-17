#include <iostream>
#include "../inc/Hen.h"

void Hen::display()
{
    std::cout << "I am a hen: " << typeid(this).name() << std::endl;
    std::cout << "My address is: " << (long)this << std::endl;
}