#include <iostream>
#include "../inc/CppTime.h"

class A
{
public:
    A() { std::cout << "Default A constructor (inline)" << std::endl; }
};

class B
{
public:
    B();
};

B::B()
{
    std::cout << "Default B constructor (non-inline)" << std::endl;
}

int main()
{
    const int COUNT = 500000;

    Time inlineStart;

    for (int i = 0; i < COUNT; i++)
    {
        A aObj;
    }

    Time inlineEnd;
    Time nInlineStart;

    for (int i = 0; i < COUNT; i++)
    {
        B aObj;
    }

    Time nInlineEnd;

    std::cout
        << "\nInline constructors' execution time: "
        << inlineEnd.delta(&inlineStart)
        << "s"
        << std::endl;

    std::cout
        << "Non-inline constructors' execution time: "
        << nInlineEnd.delta(&nInlineStart)
        << "s"
        << std::endl;

    return 0;
}