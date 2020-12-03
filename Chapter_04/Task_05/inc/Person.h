#ifndef PERSON_H
#define PERSON_H

struct Person
{
    int m_age;
    Person();

    void setAge(int age);
    void printAge();
};

#endif // PERSON_H