#include <iostream>

#define PRINT_ADDRESS_AND_VALUE(EXP)                            \
    std::cout <<                                                \
            #EXP ":" << std::endl <<                            \
            " Address: " << (long)(void *)EXP << std::endl <<   \
            " Value: " << EXP << std::endl;

char *func(const char *text)
{
    const int SIZE = sizeof(text) / sizeof(text[0]);
    char *newText = new char[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        newText[i] = text[i];
    }

    return newText;
}

int main()
{
    char *copy1 = func("text");
    char *copy2 = func(copy1);

    PRINT_ADDRESS_AND_VALUE(copy1);
    PRINT_ADDRESS_AND_VALUE(copy2);

    delete[] copy1;
    delete[] copy2;

    return 0;
}
