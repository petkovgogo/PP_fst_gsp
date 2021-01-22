#include <iostream>

int main()
{
    int y = 42;
    int &r = y;

    int x = 0;
    int &a = x;

    std::cout << "a is a reference to x. Changing its value will change the value of x as well (like a pointer)" << std::endl;
    std::cout
        << "x = " << x
        << ", ++a = " << ++a // no dereferencing needed
        << ", x = " << x // value is changed
        << std::endl;

    std::cout << "Assigning the value of r (reference to y) to a (reference of x)" << std::endl;

    a = y; // automatically dereferenced

    std::cout << "x = " << x << std::endl; // value is changed
}