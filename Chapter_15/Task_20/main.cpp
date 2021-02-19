#include <iostream>
#include <ctime>

class Base
{
public:
    virtual void func1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    void func2() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Derived : public Base
{
public:
    void func1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

int main()
{
    Derived dObj;
    Base *basePtr = &dObj;

    const int COUNT = 25;

    clock_t vmfuncStart = clock(); // start for the virtual member function

    for (int i = 0; i < COUNT; i++)
    {
        basePtr->func1();
    }

    clock_t vmfuncEnd = clock();

    clock_t mfuncStart = clock(); // start for the (non-virtual) member function

    for (int i = 0; i < COUNT; i++)
    {
        basePtr->func2();
    }

    clock_t mfuncEnd = clock();

    std::cout << "\nTime for the virtual member function: "
              << (vmfuncEnd - vmfuncStart) / (double)CLOCKS_PER_SEC / COUNT << std::endl;

    std::cout << "\nTime for the non-virtual member function: "
              << (mfuncEnd - mfuncStart) / (double)CLOCKS_PER_SEC / COUNT << std::endl;

    return 0;
}