#include <iostream>

class Base
{
private:
    int m_num;

public:
    Base(int num) : m_num(num) {}
};

class Derived : public Base
{
private:
    int m_bonusNum;

public:
    Derived(int num) : Base(num), m_bonusNum(num) {}
};

#define PRINT(EXP) \
    std::cout << #EXP " -> " << EXP << std::endl;

void passByValue(Base baseObj)
{
    // the compiler performs an object slicing, because the argument is passed by value.
    // Because of that the derived's m_bonusNum is sliced and the size becomes the one of a base object
    PRINT(sizeof(baseObj))
}

int main()
{
    Derived dObj(42);

    PRINT(sizeof(dObj))
    passByValue(dObj);

    return 0;
}