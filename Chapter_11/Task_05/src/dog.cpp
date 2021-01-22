#include "../inc/Dog.h"

#include <iostream>

Dog::Dog() : m_sound("Woof Woof") {}

void Dog::changeSound(const char *newSound)
{
    m_sound = newSound;
}

void Dog::sniff() const
{
    std::cout << "Sniff sniff..." << std::endl;
}

void Dog::bark() const
{
    std::cout << m_sound << std::endl;
}
