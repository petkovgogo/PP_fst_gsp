#include <iostream>

class Fi
{
public:
    Fi() { std::cout << "using Fi()" << std::endl; }
};

class Fee
{
public:
    Fee(int) { std::cout << "using Fee(int)" << std::endl; }
    Fee(const Fi &) { std::cout << "using Fee(const Fi &)" << std::endl; }
};

int main()
{
    Fee fee = 1;  // prints the constructor's message
    Fee fem(42);  // prints the constructor's message

    Fi fi;
    Fee fum = fi; // prints the copy-constructor's message
    Fee fam(fi);  // prints the copy-constructor's message

    return 0;
}