#include <iostream>

class MyClass
{
    volatile int m_num;

public:
    MyClass();

    void setNum(int num);
    void setVolNum(int num) volatile;
    void print() volatile;
};

MyClass::MyClass()
{
    m_num = 42;
}

void MyClass::setNum(int num)
{
    m_num = num;
}

void MyClass::setVolNum(int num) volatile
{
    m_num = num;
}

void MyClass::print() volatile
{
    std::cout << m_num << std::endl;
}

int main()
{
    MyClass myObj;
    volatile MyClass myConstObj;

    myObj.setNum(451);
    myObj.setVolNum(42);
    // error: the object has type qualifiers that are not compatible with the member function "MyClass::setNum" -- object type is: volatile MyClass
    // myConstObj.setNum(451);
    myConstObj.setVolNum(451);

    myObj.print(); // OK even if non-volatile
    myConstObj.print();

    return 0;
}