#include <iostream>

#define PRINT(EXP) \
    std::cout << #EXP " -> " << EXP << std::endl;

struct Point
{
    short x;
    short y;
};

struct Calculator
{
    int num1;
    int num2;

    int add() { return num1 + num2; }
    int substract() { return num1 - num2; }
    int mult() { return num1 * num2; }
    double divide() { return (double)num1 / num2; }
};

struct EmptyStruct
{
    /* data */
};

int main()
{
    Point point;
    Calculator calculator;
    EmptyStruct emptyStruct;

    PRINT(sizeof(point));
    PRINT(sizeof(calculator));
    PRINT(sizeof(emptyStruct)); // Празните структури имат размер 1 byte, за да не съвпада адресът на обектите им с този на друг обект

    return 0;
}
