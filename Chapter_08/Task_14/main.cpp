#include <iostream>

float getValue(float num)
{
    const float &CONST_NUM = num;

    //! CONST_NUM = 6.63; // expression must be a modifiable lvalue

    return CONST_NUM;
}

int main()
{
    std::cout << getValue(3.14F) << std::endl;

    return 0;
}