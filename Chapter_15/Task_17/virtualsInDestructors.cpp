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
    ~Derived()
    {
        std::cout << "~Derived()\n";
        f();
    }

    void f() { std::cout << "Derived::f()\n"; }
};

class SecondDerived : public Derived
{
public:
    ~SecondDerived()
    {
        std::cout << "~SecondDerived()\n";
        f();
    }

    void f() { std::cout << "SecondDerived::f()\n"; }
};

int main()
{
    Base *bp = new SecondDerived; // Upcast
    
    // each destructor calls its local f() function, because it is sure
    // that the destructor of every next class, which inherits from its own, has been
    // called already (virtual destructors are called in an order opposite of the inheritance)
    delete bp;

    return 0;
}