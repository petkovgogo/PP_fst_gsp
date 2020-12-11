#include <iostream>
#include "../inc/Libc.h"

int main()
{
    Libc libc;

    libc.setA("Lorem ipsum");
    libc.setB("Dolor sit amet");
    libc.setC("Consectetur adipiscing elit");

    std::cout << "a: " << libc.getA() << std::endl;
    std::cout << "b: " << libc.getB() << std::endl;
    std::cout << "c: " << libc.getC() << std::endl;

    return 0;
}
