#include <iostream>

#define PRINT_SIZE(EXP) \
    std::cout << #EXP " = " << EXP << std::endl;

int main()
{
    PRINT_SIZE(sizeof(char));
    PRINT_SIZE(sizeof(bool));
    PRINT_SIZE(sizeof(short));
    PRINT_SIZE(sizeof(int));
    PRINT_SIZE(sizeof(long));
    PRINT_SIZE(sizeof(float));
    PRINT_SIZE(sizeof(double));
    PRINT_SIZE(sizeof(long double));

    return 0;
}
