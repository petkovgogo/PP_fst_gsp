#include <iostream>
#include <string>

class Person
{
    std::string m_name;

public:
    Person(std::string name) : m_name(name)
    {
        std::cout << "Hi! I am ";
        printName(); // call without forward declaration
    }

    void changeName(std::string name)
    {
        m_name = name;

        std::cout << "Changed name to ";
        printName(); // call without forward declaration
    }

    void printName() const
    {
        std::cout << m_name << std::endl;
    }
};

int main()
{
    const char *NAME_1 = "Pesho";
    const char *NAME_2 = "Gosho";

    Person person(NAME_1);

    person.changeName(NAME_2);

    return 0;
}