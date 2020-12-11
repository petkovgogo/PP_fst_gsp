#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person
{
private:
    std::string m_firstName;
    int m_age;
    void singFavSong();

protected:
    std::string m_lastName;

public:
    std::vector<std::string> m_hobbies;

    Person(std::string firstName, std::string lastName, int age);
    ~Person();

    void introduceSelf();
};

#endif // PERSON_H