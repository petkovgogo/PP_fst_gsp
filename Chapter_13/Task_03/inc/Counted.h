#ifndef COUNTED_H
#define COUNTED_H

#include <iostream>

class Counted
{
private:
    static int count;
    int m_id;

public:
    Counted();
    ~Counted();
};

int Counted::count;

inline Counted::Counted() : m_id(count++)
{
    std::cout << "Counted object #" << m_id << " created." << std::endl;
}

inline Counted::~Counted()
{
    std::cout << "Counted object #" << m_id << " destroyed." << std::endl;
}

#endif // COUNTED_H