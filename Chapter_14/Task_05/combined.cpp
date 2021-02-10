#include <iostream>

class A
{
private:
    int m_num;

public:
    A(int num) : m_num(num) { std::cout << "Inside A::A()" << std::endl; }
    ~A() { std::cout << "Inside A::~A()" << std::endl; }

    void f() const {}
};

class B
{
private:
    int m_num;

public:
    B(int num) : m_num(num) { std::cout << "Inside B::B()" << std::endl; }
    ~B() { std::cout << "Inside B::~B()" << std::endl; }

    void f() const {}
};

class C : public B
{
private:
    A m_aObj;

public:
    C(int num) : B(num), m_aObj(num) { std::cout << "Inside C::C()" << std::endl; }
    ~C() { std::cout << "Inside C::~C()" << std::endl; } // Calls ~A() and ~B()

    void f() const // Redefinition
    { 
        m_aObj.f();
        B::f();
    }
};

class D : public B
{
private:
    C m_cObj;

public:
    D(int num) : B(num), m_cObj(num) { std::cout << "Inside D::D()" << std::endl; }
    ~D() { std::cout << "Inside D::~D()" << std::endl; }
    
    void f() const {}
};

int main()
{
    D dObj(42);

    return 0;
}