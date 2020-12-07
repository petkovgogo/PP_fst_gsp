#include <iostream>

const int SIZE = 5;

#define PRINT_ELEMENT_ADDRESSES(TYPE, ARR)\
    std::cout << "sizeof("#TYPE") = " << sizeof(TYPE) << std::endl;\
    for (int i = 0; i < SIZE; i++)\
    {\
        std::cout << "&arr[" << i << "] = " << (long)&ARR[i] << std::endl;\
    }\
    \
    std::cout << std::endl; 

int main()
{
    int intArr[SIZE];
    char charArr[SIZE];
    long longArr[SIZE];
    float floatArr[SIZE];
    double doubleArr[SIZE];

    PRINT_ELEMENT_ADDRESSES(int, intArr);
    PRINT_ELEMENT_ADDRESSES(char, charArr);
    PRINT_ELEMENT_ADDRESSES(long, longArr);
    PRINT_ELEMENT_ADDRESSES(float, floatArr);
    PRINT_ELEMENT_ADDRESSES(double, doubleArr);

    return 0;
}