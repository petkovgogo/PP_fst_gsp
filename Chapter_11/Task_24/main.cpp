#include <iostream>

class Simple;

typedef double Simple::*m_numPtr_t;
typedef void (Simple::*printPtr_t)() const;

class Simple
{
public:
    double m_num;
    void print() const { std::cout << "Number: " << m_num << std::endl; }

    Simple(double num) : m_num(num) {}
};

int main()
{
    Simple simpleObj(3.14);
    Simple *simplePtr = &simpleObj;

    m_numPtr_t m_numPtr = &Simple::m_num;
    printPtr_t printPtr = &Simple::print;

    (simpleObj.*printPtr)();

    simplePtr->*m_numPtr = 6.63;
    (simplePtr->*printPtr)();

    return 0;
}