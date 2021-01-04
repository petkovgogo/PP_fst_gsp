#include <iostream>

class MyClass
{
    int m_num;

public:
    MyClass();

    void setNum(int num);
    void print() const;
};

MyClass::MyClass()
{
    m_num = 42;
}

void MyClass::setNum(int num)
{
    m_num = num;
}

void MyClass::print() const
{
    std::cout << m_num << std::endl;
}

int main()
{
    MyClass myObj;
    const MyClass myConstObj;

    myObj.setNum(451);
    // error: the object has type qualifiers that are not compatible with the member function "MyClass::setNum" -- object type is: const MyClass
    // myConstObj.setNum(451);

    myObj.print();
    myConstObj.print();

    return 0;
}