#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "StringVector.h"
#include "TContainer.h"

int main()
{
    StringVector lines;
    std::ifstream source("vectorTest.cpp");
    std::string line;

    while (getline(source, line))
    {
        lines.push_back(new std::string(line));
    }

    TContainer<int> numbers;

    for (size_t i = 1; i <= lines.size(); i++)
    {
        numbers.push_back(new int(i));
    }

    for (size_t i = 0; i < numbers.size(); i++)
    {
        std::cout << std::right << std::setw(2) << *numbers[i] << ": " << *lines[i] << std::endl;

        delete numbers[i];
        delete lines[i];
    }
    
    return 0;
}