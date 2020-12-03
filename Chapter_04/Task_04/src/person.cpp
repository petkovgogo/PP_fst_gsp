#include <iostream>
#include "../inc/Person.h"

Person::Person()
{
    m_age = 0;
}

void setAge(Person &person, int age)
{
    person.m_age = age;
}

void printAge(Person &person)
{
    std::cout << "I am " << person.m_age << " years old." << std::endl;
}