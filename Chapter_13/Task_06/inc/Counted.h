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

    void f() const;

    friend std::ostream &operator<<(std::ostream &out, Counted &countedObj);
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

inline void Counted::f() const
{
    std::cout << "Inside void Counted::f()" << std::endl;
}

inline std::ostream &operator<<(std::ostream &out, Counted &countedObj)
{
    return out << "Id: " << countedObj.m_id;
}

#endif // COUNTED_H