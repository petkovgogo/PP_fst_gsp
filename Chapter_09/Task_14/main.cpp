#include <iostream>

class A
{
public:
    A() { std::cout << "- Hello there." << std::endl; }
};

class B
{
    A aObj;

public:
    B() { std::cout << "- General Kenobi!\n" << std::endl; }
};

int main()
{
    const int SIZE = 7;

    B bArr[SIZE];

    return 0;
}