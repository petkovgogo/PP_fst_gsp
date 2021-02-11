#include <iostream>

#define CREATE_STATIC_FUNC(CLASS, ID, ARG) \
    static void ID(ARG) { std::cout << #CLASS "::" #ID "(" #ARG ") called" << std::endl; }

class Simple
{
public:
    CREATE_STATIC_FUNC(Simple, f,)
    CREATE_STATIC_FUNC(Simple, f, int)
};

class Heir : public Simple
{
public:
    CREATE_STATIC_FUNC(Heir, f,)
    // Simple::f(int) is not redefined
};

int main()
{
    Simple::f();
    Simple::f(1);
    Heir::f();
    // Heir::f(2); // error: no matching function for call to ‘Heir::f(int)’

    return 0;
}