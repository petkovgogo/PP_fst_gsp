#include <iostream>

int main()
{
    char *text = "Lorem ipsum dolor sit amet.";

    std::cout << text << std::endl;

    // The compiler does not report the changing of a string constant via char* as an error
    // Instead it gives a warning "ISO C++ forbids converting a string constant to ‘char*’"

    // I think it should report this as an error, because it causes a Segmentation fault (core dumped),
    // which is a hard to find and fix error

    // As to why it does not give an error, I think that's because it's a valid statement in C++.
    // The char* is actually an array of chars, but because it is initialized with a string literal,
    // it is treated as a C-style string (const char*). So in C++ it is valid to change the element of
    // a non-const array, and the compiler thinks it is OK, but because it is actually a C-style string,
    // it throws a Segmentation fault (core dumped)

    text[0] = 'l';

    std::cout << text << std::endl;

    return 0;
}