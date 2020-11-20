#include <iostream>
#include "../inc/Functions.h"

void printName(const char* name)
{
    std::cout << "Function: " << "void printName(const char* name)" << std::endl;
    std::cout << "Result: " << name << std::endl;
}

char getChar(char c)
{
    std::cout << "Function: " << "char getChar(char c)" << std::endl;
    std::cout << "Result: ";
    return c;
}

int sum(int num1, int num2)
{
    std::cout << "Function: " << "int sum(int num1, int num2)" << std::endl;
    std::cout << "Result: ";
    return num1 + num2;
}

float divide(float num1, float num2)
{
    std::cout << "Function: " << "float divide(float num1, float num2)" << std::endl;
    std::cout << "Result: ";
    return num1 / num2;
}
