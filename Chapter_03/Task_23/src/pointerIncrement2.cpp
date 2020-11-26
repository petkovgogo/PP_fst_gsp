#include <iostream>

union Primitives
{
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;
    long double ld;
};

int main()
{
    Primitives p[10];
    Primitives *pp = p;
    std::cout << "sizeof(Primitives) = "
              << sizeof(Primitives) << std::endl;
    std::cout << "pp = " << (long)pp << std::endl;
    pp++;
    std::cout << "pp = " << (long)pp << std::endl;

    return 0;
}