#include <iostream>

class A
{
public:
    A() { std::cout << "Inside A::A()" << std::endl; }
    ~A() { std::cout << "Inside A::~A()" << std::endl; }
};

class B : public A
{
public:
    B() { std::cout << "Inside B::B()" << std::endl; }
    ~B() { std::cout << "Inside B::~B()" << std::endl; }
};

class C : public B
{
public:
    C() { std::cout << "Inside C::C()" << std::endl; }
    ~C() { std::cout << "Inside C::~C()" << std::endl; }
};

int main()
{
    // Construction is done from base to derived class,
    // whereas the destruction is in reverse order
    C cObj;

    return 0;
}