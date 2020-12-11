#include <iostream>
#include "../inc/Person.h"

Person::Person(std::string firstName, std::string lastName, int age)
{
    m_firstName = firstName;
    m_lastName = lastName;
    m_age = age;
}

Person::~Person()
{
    m_hobbies.clear();
    m_hobbies.shrink_to_fit();
}

void Person::singFavSong()
{
    std::cout << "*starts singing*" << std::endl;
}

void Person::introduceSelf()
{
    std::cout << "Hello, my name is " <<
        m_firstName << " " << m_lastName << std::endl;
}