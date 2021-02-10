#include <iostream>
#include <string>

class Base
{
public:
    int f() const
    {
        std::cout << "Base::f()\n";
        return 1;
    }

    int f(std::string) const { return 1; }

    void g() {}

    void h() const {}
    void h(std::string) {}
    int h(int) const { return 1; }
};

class Derived1 : public Base
{
public:
    void g() const {}

    void h() const { std::cout << "Derived1::h()" << std::endl; }
};

class Derived2 : public Base
{
public:
    // Redefinition:
    int f() const
    {
        std::cout << "Derived2::f()\n";

        return 2;
    }

    void h(std::string) const { std::cout << "Derived2::h(std::string)" << std::endl; }
};

class Derived3 : public Base
{
public:
    // Change return type:
    void f() const { std::cout << "Derived3::f()\n"; }

    int h(int) const
    {
        std::cout << "Derived3::h(int)" << std::endl;

        return 3;
    }
};

class Derived4 : public Base
{
public:
    // Change argument list:
    int f(int) const
    {
        std::cout << "Derived4::f()\n";

        return 4;
    }

    void h() const { std::cout << "Derived4::h()" << std::endl; }
    void h(std::string) const { std::cout << "Derived4::h(std::string)" << std::endl; }
};

int main()
{
    std::string s("hello");

    Derived1 d1;
    int x = d1.f();
    d1.f(s);

    d1.h();
    //! d1.h(s);      // function is hidden
    //! x = d1.h(42); // function is hidden

    Derived2 d2;
    x = d2.f();
    //! d2.f(s); // std::string version hidden

    //! d2.h();       // function is hidden
    d2.h(s);
    //! x = d2.h(42); // function is hidden

    Derived3 d3;
    //! x = d3.f(); // return int version hidden

    //! d3.h();   // function is hidden
    //! d3.h(s);  // function is hidden
    x = d3.h(42);

    Derived4 d4;
    //! x = d4.f(); // f() version hidden
    x = d4.f(1);

    d4.h();
    d4.h(s);
    //! x = d4.h(42); // function is hidden

    std::cout << "x = " << x << std::endl;

    return 0;
}