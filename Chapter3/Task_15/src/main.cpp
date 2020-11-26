#include <iostream>
#include <string>

#define PRINT(EXP) std::cout << #EXP " = " << EXP << std::endl;

typedef struct
{
    std::string str1;
    std::string str2;
    int number;

} MyStruct;

int main()
{
    MyStruct myStruct;
    myStruct.str1 = "1st string";
    myStruct.str2 = "2nd string";
    myStruct.number = 42;

    PRINT(myStruct.str1);
    PRINT(myStruct.str2);
    PRINT(myStruct.number);

    MyStruct *pMyStruct = &myStruct;
    pMyStruct->str1 = "1st string edited";
    pMyStruct->str2 = "2nd string edited";
    pMyStruct->number = 345;

    PRINT(pMyStruct->str1);
    PRINT(pMyStruct->str2);
    PRINT(pMyStruct->number);

    return 0;
}