#include <iostream>

class MyClass
{
    int m_number;

public:
    // MyClass(int number);
    void printValue();
};

/*
MyClass::MyClass(int number)
{
    m_number = number;
}
*/

void MyClass::printValue()
{
    std::cout << m_number << std::endl;
}

int main()
{
    MyClass myObj;

    myObj.printValue(); // The value is not initialized with the default constructor

    return 0;
}