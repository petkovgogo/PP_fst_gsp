#include <iostream>

class Base
{
public:
    virtual ~Base()
    {
        std::cout << "~Base1()\n";
        f();
    }

    virtual void f() { std::cout << "Base::f()\n"; }
};

class Derived : public Base
{
public:
    ~Derived() { std::cout << "~Derived()\n"; }

    void f() { std::cout << "Derived::f()\n"; }
};

class SecondDerived : public Derived
{
public:
    ~SecondDerived() { std::cout << "~SecondDerived()\n"; }

    void f() { std::cout << "SecondDerived::f()\n"; }
};

int main()
{
    Base *bp = new SecondDerived; // Upcast
    delete bp;

    return 0;
}