#include <iostream>

const int SIZE = 10;

#define PRINT_ELEMENT_ADDRESSES(TYPE, ARR)\
    std::cout << "sizeof("#TYPE") = " << sizeof(TYPE) << std::endl;\
    for (int i = 0; i < SIZE; i++)\
    {\
        std::cout << "&arr[" << i << "] = " << (long)&ARR[i] << std::endl;\
    }\
    \
    std::cout << std::endl; 

typedef struct
{
    int i, j, k;
} ThreeDpoint;

int main()
{
    ThreeDpoint p[SIZE];

    PRINT_ELEMENT_ADDRESSES(ThreeDpoint, p);

    return 0;
}