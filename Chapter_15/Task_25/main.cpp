#include <iostream>
#include <string>

class Base
{
private:
    std::string m_name;

public:
    Base(std::string type, int id) : m_name(type + " object #" + std::to_string(id++)) {}
    Base(Base &origin) : m_name(origin.m_name + " copy") {}

    std::string identify() { return m_name; }

    virtual Base *clone() = 0;
};

class Derived1 : public Base
{
private:
    static int id;

public:
    Derived1() : Base("Derived1", id++) {}
    Derived1(Derived1 &origin) : Base(origin) {}

    Base *clone() { return new Derived1(*this); }
};

int Derived1::id;

class Derived2 : public Base
{
private:
    static int id;

public:
    Derived2() : Base("Derived2", id++) {}
    Derived2(Derived2 &origin) : Base(origin) {}

    Derived2 *clone() { return new Derived2(*this); }
};

int Derived2::id;

#define PRINT(EXP) \
    std::cout << #EXP " -> " << EXP << std::endl;

int main()
{
    Derived1 *dObj1 = new Derived1;
    Derived2 *dObj2 = new Derived2;

    PRINT(dObj1->identify())
    PRINT(dObj2->identify())

    Base *copy1 = dObj1->clone();
    Base *copy2 = dObj2->clone();

    PRINT(copy1->identify())
    PRINT(copy2->identify())

    return 0;
}