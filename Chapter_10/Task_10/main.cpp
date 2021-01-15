#include <iostream>
#include "Static.h"

void print1(); // extern by default
void print2(); // extern by default

int main()
{
    std::cout << "main(): " << num << std::endl;

    print1();
    print2();

    return 0;
}