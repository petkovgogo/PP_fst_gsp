#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <ctime>

class Person;
std::ostream &operator<<(std::ostream &out, Person &person);

class Person
{
private:
    std::string m_firstName;
    std::string m_lastName;
    struct tm m_dateRented;
    struct tm m_dateDue;

public:
    Person(std::string firstName, std::string lastName);
    ~Person();

    void setDateRented();
    void setDateDue(struct tm dateDue);
    struct tm getDateRented();

    friend std::ostream &operator<<(std::ostream &out, Person &person);
};

#endif // PERSON_H