#include <iostream>
#include <cstring>

#define PRINT_ADDRESS_AND_VALUE(EXP)                    \
    std::cout << #EXP ":" << std::endl                  \
              << " Address: " << (long)EXP << std::endl \
              << " Value: " << EXP << std::endl;

char *func(char *text)
{
    const int SIZE = strlen(text);
    char *newText = new char[SIZE + 1]; // + 1 for the '\0'

    for (int i = 0; i < SIZE; i++)
    {
        newText[i] = text[i];
    }

    newText[SIZE] = '\0';

    return newText;
}

int main()
{
    char text[] = "sample text";
    char *copy1 = func(text);
    char *copy2 = func(copy1);

    PRINT_ADDRESS_AND_VALUE(copy1);
    PRINT_ADDRESS_AND_VALUE(copy2);

    delete[] copy1;
    delete[] copy2;

    return 0;
}
