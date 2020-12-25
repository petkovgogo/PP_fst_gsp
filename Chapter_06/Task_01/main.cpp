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

Simple::~Simple() {}

int main()
{
    Simple simple;

    return 0;
}