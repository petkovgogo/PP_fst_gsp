#include <iostream>
#include "../inc/Hen.h"

void Hen::display()
{
    std::cout << "I am a hen: " << typeid(this).name() << std::endl;
}

void Hen::Nest::display()
{
    std::cout << "I am a nest: " << typeid(this).name() << std::endl;
}

void Hen::Nest::Egg::display()
{
    std::cout << "I am an egg: " << typeid(this).name() << std::endl;
}