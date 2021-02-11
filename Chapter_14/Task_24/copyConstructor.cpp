#include <iostream>

class Parent
{
private:
    int i;

public:
    Parent(int ii) : i(ii) { std::cout << "Parent(int ii)\n"; }
    Parent(const Parent &b) : i(b.i) { std::cout << "Parent(const Parent&)\n"; }
    Parent() : i(0) { std::cout << "Parent()\n"; }

    friend std::ostream &operator<<(std::ostream &os, const Parent &b)
    {
        return os << "Parent: " << b.i << std::endl;
    }
};

class Member
{
private:
    int i;

public:
    Member(int ii) : i(ii) { std::cout << "Member(int ii)\n"; }
    Member(const Member &m) : i(m.i) { std::cout << "Member(const Member&)\n"; }

    friend std::ostream &operator<<(std::ostream &os, const Member &m)
    {
        return os << "Member: " << m.i << std::endl;
    }
};

#define EXPLICIT_CALL

class Child : public Parent
{
private:
    int i;
    Member m;

public:
    Child(int ii) : Parent(ii), i(ii), m(ii) { std::cout << "Child(int ii)\n"; }

#ifdef EXPLICIT_CALL

    Child(const Child &child) : Parent(child), i(child.i), m(child.m)
    {
        std::cout << "Child(const Child&)" << std::endl;
    }

#else

    // warning: base class ‘class Parent’ should be explicitly initialized in the copy constructor
    Child(const Child &child) : i(child.i), m(child.m)
    {
        std::cout << "Child(const Child&)" << std::endl;
    }

#endif // EXPLICIT_CALL

    friend std::ostream &operator<<(std::ostream &os, const Child &c)
    {
        return os << (Parent &)c << c.m
                  << "Child: " << c.i << std::endl;
    }
};

int main()
{
    Child c(2);

    std::cout << "\ncalling copy-constructor: " << std::endl;
    Child c2 = c; // Calls copy-constructor

    std::cout << "\nvalues in c2:\n"
              << c2 << std::endl;

    return 0;
}