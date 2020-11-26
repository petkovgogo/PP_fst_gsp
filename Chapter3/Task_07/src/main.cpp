#include <iostream>

#define PRINT(EXP) std::cout << #EXP << ": " << EXP << std::endl; 

void modifyPointer(std::string* text)
{
    *text = "Modified by 1st function";
}

void modifyReference(std::string &text)
{
    text = "Modified by 2nd function";
}

int main()
{
    std::string textVar("Sample text");

    PRINT(textVar);

    modifyPointer(&textVar);
    PRINT(textVar);

    modifyReference(textVar);
    PRINT(textVar);

    return 0;
}