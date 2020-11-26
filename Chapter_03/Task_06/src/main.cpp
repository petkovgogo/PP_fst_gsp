#include <iostream>

#define CALL_FUNC(EXP)\
    std::cout << std::endl;\
    std::cout << #EXP << "(): " << (long)&EXP << std::endl;\
    EXP();

#define PRINT_VAR_ADDRESS(EXP) std::cout << #EXP << ": " << (long)&EXP << std::endl;

void printChars()
{
    char ch1, ch2, ch3;
    PRINT_VAR_ADDRESS(ch1);
    PRINT_VAR_ADDRESS(ch2);
    PRINT_VAR_ADDRESS(ch3);
}

void printShortInts()
{
    short int si_num1, si_num2, si_num3;
    PRINT_VAR_ADDRESS(si_num1);
    PRINT_VAR_ADDRESS(si_num2);
    PRINT_VAR_ADDRESS(si_num3);
}

void printInts()
{
    int i_num1, i_num2, i_num3;
    PRINT_VAR_ADDRESS(i_num1);
    PRINT_VAR_ADDRESS(i_num2);
    PRINT_VAR_ADDRESS(i_num3);
}

void printLongInts()
{
    long int li_num1, li_num2, li_num3;
    PRINT_VAR_ADDRESS(li_num1);
    PRINT_VAR_ADDRESS(li_num2);
    PRINT_VAR_ADDRESS(li_num3);
}

void printFloats()
{
    float f_num1, f_num2, f_num3;
    PRINT_VAR_ADDRESS(f_num1);
    PRINT_VAR_ADDRESS(f_num2);
    PRINT_VAR_ADDRESS(f_num3);
}

void printDoubles()
{
    double d_num1, d_num2, d_num3;
    PRINT_VAR_ADDRESS(d_num1);
    PRINT_VAR_ADDRESS(d_num2);
    PRINT_VAR_ADDRESS(d_num3);
}

void printLongDoubles()
{
    long double ld_num1, ld_num2, ld_num3;
    PRINT_VAR_ADDRESS(ld_num1);
    PRINT_VAR_ADDRESS(ld_num2);
    PRINT_VAR_ADDRESS(ld_num3);
}

int main()
{
    CALL_FUNC(printChars);
    CALL_FUNC(printShortInts);
    CALL_FUNC(printInts);
    CALL_FUNC(printLongInts);
    CALL_FUNC(printFloats);
    CALL_FUNC(printDoubles);
    CALL_FUNC(printLongDoubles);

    return 0;
}