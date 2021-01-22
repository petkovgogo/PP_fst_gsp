#include <iostream>

void modifyValue(char &c)
{
    c = 42; // no dereferencing => cleaner code
}

int main()
{
    char symbol = 47;
    
    std::cout << "Before: " << symbol << std::endl;
    modifyValue(symbol); // no & to pass address => the code is more readable
    std::cout << "After:  " << symbol << std::endl;

    return 0;
}