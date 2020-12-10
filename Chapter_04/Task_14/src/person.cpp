#include <iostream>
#include <string>
#include <ctime>
#include <exception>
#include "../inc/Person.h"

Person::Person(std::string firstName, std::string lastName)
{
    m_firstName = firstName;
    m_lastName = lastName;
}

Person::~Person() {}

// Set the date rented to current date
void Person::setDateRented()
{
    time_t currTime = time(0);
    m_dateRented = *localtime(&currTime);
}

void Person::setDateDue(struct tm dateDue)
{
    // Perform different checks to assure the due date is correct
    bool yearCheck = dateDue.tm_year < m_dateRented.tm_year;
    bool monthCheck = dateDue.tm_mon < m_dateRented.tm_mon;
    bool dayCheck = dateDue.tm_mday <= m_dateRented.tm_mday;

    if (yearCheck || monthCheck || dayCheck)
    {
        throw std::invalid_argument("Due date cannot be before rented date and cannot be at the same day");
    }

    m_dateDue = dateDue;
}

struct tm Person::getDateRented()
{
    return m_dateRented;
}

std::ostream &operator<<(std::ostream &out, Person &person)
{
    out << " First name: " << person.m_firstName << std::endl;
    out << " Last name: " << person.m_lastName << std::endl;
    out << " Date rented: " << 
        person.m_dateRented.tm_mday << "." << 
        person.m_dateRented.tm_mon + 1 << "." << 
        person.m_dateRented.tm_year + 1900 << std::endl;
    out << " Date due: " << 
        person.m_dateDue.tm_mday << "." << 
        person.m_dateDue.tm_mon + 1 << "." << 
        person.m_dateDue.tm_year + 1900 << std::endl;

    return out;
}
