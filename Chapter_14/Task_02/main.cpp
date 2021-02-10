#include <iostream>

class A
{
public:
    A() { std::cout << "Inside A::A()" << std::endl; }
};

class B
{
public:
    B() { std::cout << "Inside B::B()" << std::endl; }
};

class C : public A
{
private:
    B m_bObj;
};

int main()
{
    C cObj;

    return 0;
}