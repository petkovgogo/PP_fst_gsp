#include <iostream>

class Base1
{
public:
    virtual void func1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Base2
{
public:
    virtual void func2() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Derived1 : public Base1
{
public:
    void func1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Derived2 : public Base1, public Base2
{
public:
    void func1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    void func2() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

int main()
{
    Derived1 d1;
    Derived2 d2;

    // As seen from the output the vptr has the size of a normal void * (for 64 bit machines it is 8 bytes, for 32 bit - 4 bytes).
    // When it comes to multiple inheritance, the size of the class is twice as big (16 bytes on my computer), meaning there are
    // two vptrs - one for each inherited class.
    std::cout << "VPTR of single inheritance: " << sizeof(d1) << " bytes" << std::endl;
    std::cout << "VPTR of multiple inheritance: " << sizeof(d2) << " bytes" << std::endl;

    return 0;
}