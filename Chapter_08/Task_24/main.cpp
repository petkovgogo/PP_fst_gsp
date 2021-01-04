#include <iostream>

class MyClass
{
    int m_num;

public:
    MyClass();

    void setNum(int num);
    void print(int num = 0) const;
};

MyClass::MyClass()
{
    m_num = 42;
}

void MyClass::setNum(int num)
{
    m_num = num;
    print(); // OK
}

void MyClass::print(int num) const
{
    // error: the object has type qualifiers that are not compatible with the member function "MyClass::setNum" -- object type is: const MyClass
    // setNum(num);
    std::cout << m_num << std::endl;
}

int main()
{
    MyClass myObj;
    const MyClass myConstObj;

    myObj.setNum(451);
    // error: the object has type qualifiers that are not compatible with the member function "MyClass::setNum" -- object type is: const MyClass
    // myConstObj.setNum(451);

    myConstObj.print(470);

    return 0;
}