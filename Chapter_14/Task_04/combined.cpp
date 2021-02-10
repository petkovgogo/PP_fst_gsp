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

class B : public A
{
private:
    int m_num;

public:
    B(int num) : A(num), m_num(num) { std::cout << "Inside B::B()" << std::endl; }
    ~B() { std::cout << "Inside B::~B()" << std::endl; }

    void f() const {}
};

class C : public B
{
private:
    int m_num;

public:
    C(int num) : B(num), m_num(num) { std::cout << "Inside C::C()" << std::endl; }
    ~C() { std::cout << "Inside C::~C()" << std::endl; } // Calls ~A() and ~B()

    void f() const
    { // Redefinition
        A::f();
        B::f();
    }
};

class D
{
private:
    int m_num;

public:
    D(int num) : m_num(num) { std::cout << "Inside D::D()" << std::endl; }
    ~D() { std::cout << "Inside D::~D()" << std::endl; }
    
    void f() const {}
};

class E
{
private:
    C m_cObj;
    D m_dObj;

public:
    E(int num) : m_cObj(num), m_dObj(num) { std::cout << "Inside E::E()" << std::endl; }
    ~E() { std::cout << "Inside E::~E()" << std::endl; }
    
    void f() const
    {
        m_cObj.f();
        m_dObj.f();
    }
};

int main()
{
    E eObj(42);

    return 0;
}