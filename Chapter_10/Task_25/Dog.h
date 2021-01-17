#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>

class Dog
{
private:
    std::string m_name;
    
public:
    Dog(std::string name);

    void print();
};

inline Dog::Dog(std::string name)
{
    m_name = name;
}

void inline Dog::print()
{
    std::cout << "The dog is called " << m_name << std::endl;
}

#endif // DOG_H