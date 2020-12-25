#include <iostream>
#include "../inc/Stack2.h"

int main()
{
    std::string stringArr[] = {"Lorem", "ipsum", "dolor", "sit", "amet,", "consectetur", "adipiscing", "elit.", "Morbi", "vel", "orci", "dui."};

    Stack stringStack;

    for (int i = 0; i < sizeof(stringArr) / sizeof(*stringArr); i++)
    {
        stringStack.push(new std::string(stringArr[i]));
    }

    std::string *word;

    while ((word = (std::string *)stringStack.pop()) != 0)
    {
        std::cout << *word << " ";
        delete word;
    }

    std::cout << std::endl;

    return 0;
}