#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Call of ";

        func1();

        std::cout << " from " << __PRETTY_FUNCTION__ << std::endl;
    }

    virtual void func1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    void func2()
    {
        std::cout << "Call of ";

        func1();

        std::cout << " from " << __PRETTY_FUNCTION__ << std::endl;
    }
};

class Derived : public Base
{
public:
    void func1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

int main()
{
    // as seen from the first message in the console, when the Base class constructor
    // is called, it uses Base::func1(), even though a Derived object is created
    Derived derivedObj;
    Base &baseRef = derivedObj;

    // here the Derived::func1() is used from the normal member function Base::func2()
    baseRef.func2();

    return 0;
}