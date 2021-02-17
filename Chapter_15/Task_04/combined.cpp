#include <iostream>

class A
{
private:
    int i;

public:
    A(int ii) : i(ii) {}
    ~A() {}

    void f() const { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class B
{
private:
    int i;

public:
    B(int ii) : i(ii) {}
    ~B() {}

    virtual void f() const { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class C : public B
{
private:
    A a;

public:
    C(int ii) : B(ii), a(ii) {}
    ~C() {} // Calls ~A() and ~B()

    void f() const
    { 
        std::cout << "Inside: " << __PRETTY_FUNCTION__ << "\nCalling: " << std::endl;

        a.f();
        B::f();
    }
};

int main()
{
    C c(47);
    B &bRef = c;

    bRef.f();

    return 0;
}