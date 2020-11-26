#include <iostream>

//Different outputs for the first part are in the outputs folder

union Packed
{
    char i;
    short j;
    int k;
    long l;
    float f;
    double d;
};

int main()
{
    std::cout << "sizeof(Packed) = "
              << sizeof(Packed) << std::endl;
    
    Packed packed;

    std::cout << "Asigning value to short" << std::endl;
    packed.j = 42;

    std::cout << "Printing via int: " << packed.i << std::endl;

    std::cout << "Asigning value to float" << std::endl;
    packed.f = 6.63;

    std::cout << "Printing via int: " << packed.i << std::endl;

    return 0;
}