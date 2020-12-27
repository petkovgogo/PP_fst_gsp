#include <iostream>
#include "../inc/Stack2.h"

int main()
{
    const int SIZE = 12;

    void* stringArr[] = {

        new std::string("Lorem"),
        new std::string("ipsum"),
        new std::string("dolor"),
        new std::string("sit"),
        new std::string("amet,"),
        new std::string("consectetur"),
        new std::string("adipiscing"),
        new std::string("elit."),
        new std::string("Morbi"),
        new std::string("vel"),
        new std::string("orci"),
        new std::string("dui.")
        
    };

    Stack stringStack(stringArr, SIZE);

    std::string *word;

    while ((word = (std::string *)stringStack.pop()) != 0)
    {
        std::cout << *word << " ";
        delete word;
    }

    std::cout << std::endl;

    return 0;
}