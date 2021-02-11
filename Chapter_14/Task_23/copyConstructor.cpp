#include <iostream>

class Parent
{
private:
    int i;

public:
    Parent(int ii) : i(ii) { std::cout << "Parent(int ii)\n"; }
    Parent(const Parent &b) : i(b.i) { std::cout << "Parent(const Parent&)\n"; }
    Parent() : i(0) { std::cout << "Parent()\n"; }

    Parent &operator=(const Parent &origin)
    {
        std::cout << "Parent::operator=()" << std::endl;

        if (this != &origin)
        {
            this->i = origin.i;
        }

        return *this;
    }

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

    Member &operator=(const Member &origin)
    {
        std::cout << "Member::operator=()" << std::endl;

        if (this != &origin)
        {
            this->i = origin.i;
        }

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Member &m)
    {
        return os << "Member: " << m.i << std::endl;
    }
};

class Child : public Parent
{
private:
    int i;
    Member m;

public:
    Child(int ii) : Parent(ii), i(ii), m(ii) { std::cout << "Child(int ii)\n"; }

    friend std::ostream &operator<<(std::ostream &os, const Child &c)
    {
        return os << (Parent &)c << c.m
                  << "Child: " << c.i
                  << std::endl;
    }
};

class GrandChild : public Child
{
private:
    int i;
    Member m;

public:
    GrandChild(int ii) : Child(ii), i(ii), m(ii) { std::cout << "GrandChild(int ii)\n"; }
    GrandChild(const GrandChild &gc) : Child(gc), i(gc.i), m(gc.m) { std::cout << "GrandChild(const GrandChild&)\n"; }

    GrandChild &operator=(const GrandChild &origin)
    {
        std::cout << "GrandChild::operator=()" << std::endl;

        if (this != &origin)
        {
            Child::operator=(origin);
            this->i = origin.i;
            this->m = origin.m;
        }

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const GrandChild &gc)
    {
        return os << (Child &)gc << gc.m
                  << "GrandChild: " << gc.i
                  << std::endl;
    }
};

#define PRINT(EXP)                       \
    std::cout << "values in " #EXP ":\n" \
              << EXP << std::endl;

int main()
{
    GrandChild gc1(3);

    std::cout << "\ncalling copy-constructor: " << std::endl;
    GrandChild gc2(gc1);

    PRINT(gc2)

    GrandChild gc3(5);

    PRINT(gc3)
    PRINT((gc3 = gc2))

    return 0;
}