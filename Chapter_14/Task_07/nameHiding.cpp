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
};

class Derived1 : public Base
{
public:
    void g() const {}
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
};

class Derived3 : public Base
{
public:
    // Change return type:
    void f() const { std::cout << "Derived3::f()\n"; }
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
};

// All functions within the SHOW_ERROR #ifdefs throw errors,
// because one or more of their overloads are redefined, therefore
// all other overloads are hidden

// #define SHOW_ERROR

int main()
{
    std::string s("hello");

    Derived1 d1;
    int x = d1.f();
    d1.f(s);

    Derived2 d2;
    x = d2.f();

#ifdef SHOW_ERROR

    d2.f(s); // std::string version hidden

#endif // SHOW_ERROR

    Derived3 d3;

#ifdef SHOW_ERROR

    x = d3.f(); // return int version hidden

#endif // SHOW_ERROR

    Derived4 d4;

#ifdef SHOW_ERROR

    x = d4.f(); // f() version hidden

#endif // SHOW_ERROR

    x = d4.f(1);

    return 0;
}