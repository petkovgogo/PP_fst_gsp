#include <iostream>

class Base
{
public:
    virtual void func() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Derived : public Base
{
public:
    void func() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

int main()
{
    Derived dObj;
    Base &baseRef = dObj;

    baseRef.func();

    return 0;
}