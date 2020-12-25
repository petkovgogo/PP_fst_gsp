#include <iostream>

class Simple
{
public:
    Simple();
    ~Simple();
};

Simple::Simple()
{
    std::cout << "Hello, I am the constructor of a Simple object!" << std::endl;
}

Simple::~Simple() 
{
    std::cout << "I am the destructor of a Simple object! Goodbye..." << std::endl;
}

int main()
{
    Simple simple;

    return 0;
}