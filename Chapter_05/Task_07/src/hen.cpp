#include <iostream>
#include "../inc/Hen.h"

void Hen::display(Hen::Nest &nest)
{
    std::cout << "I am a hen: " << typeid(this).name() << std::endl;
    std ::cout << "I have a nest " << typeid(nest).name() << " with " << nest.m_eggCount << " eggs." << std::endl;
}

Hen::Nest::Nest()
{
    m_eggCount = 0;
}

void Hen::Nest::addEgg()
{
    m_eggCount++;
}

void Hen::Nest::display(Hen::Nest::Egg &egg)
{
    std::cout << "I am a nest: " << typeid(this).name() << std::endl;
    std ::cout << "I have an egg " << typeid(egg).name() << " with " << egg.m_colour << " colour." << std::endl;
}

Hen::Nest::Egg::Egg(const char *colour)
{
    m_colour = colour;
}