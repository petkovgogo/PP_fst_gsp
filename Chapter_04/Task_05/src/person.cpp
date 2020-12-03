#include <iostream>
#include "../inc/Person.h"

Person::Person()
{
    m_age = 0;
}

void Person::setAge(int age)
{
    m_age = age;
}

void Person::printAge()
{
    std::cout << "I am " << m_age << " years old." << std::endl;
}