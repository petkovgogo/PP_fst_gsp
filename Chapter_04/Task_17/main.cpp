#include <iostream>

#define PRINT_ADDRESS(EXP) \
    std::cout << #EXP " -> " << (long)EXP << std::endl;

int main()
{
    int* dynamicInt = new int;
    long* dynamicLong = new long;
    char* charArr = new char[100];   
    float* floatArr = new float[100];

    PRINT_ADDRESS(dynamicInt);
    PRINT_ADDRESS(dynamicLong);
    PRINT_ADDRESS(charArr);
    PRINT_ADDRESS(floatArr);

    delete dynamicInt;
    delete dynamicLong;
    delete[] charArr;
    delete[] floatArr;
    
    return 0;
}
