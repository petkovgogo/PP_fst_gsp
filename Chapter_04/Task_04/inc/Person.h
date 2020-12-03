#ifndef PERSON_H
#define PERSON_H

struct Person
{
    int m_age;
    Person();
};

void setAge(Person &person, int age);
void printAge(Person &person);

#endif // PERSON_H