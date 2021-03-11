#include "TStack2.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("TStack2Test.cpp");
    Stack<std::string> textlines;

    // Read file and store lines in the Stack:
    std::string line;
    int lineCount = 0;
    int notOwnedCount = 0;

    while (getline(file, line))
    {
        if (lineCount++ % 2 == 0)
        {
            textlines.push(new std::string(line));
        }
        else
        {
            ++notOwnedCount;
            textlines.push(new std::string(line), false);
        }
    }

    int i = 0;

    // Use iterator to print lines from the list:
    Stack<std::string>::iterator it = textlines.begin();
    Stack<std::string>::iterator *it2 = 0;

    while (it != textlines.end())
    {
        std::cout << it->c_str() << std::endl;
        it++;

        if (++i == 9) // Remember 10th line
        {
            it2 = new Stack<std::string>::iterator(it);
        }
    }

    std::cout << "\n10th popped line: " << (*it2)->c_str() << std::endl;

    delete it2;

    int deletedCount = 0;

    for (auto it3 = textlines.begin(); it3 != textlines.end(); it3++)
    {
        if (!it3.owner())
        {
            ++deletedCount;
            delete *it3;
        }
    }

    // Memory leak safeguard:
    std::cout << "\nItems not owned: " << notOwnedCount << std::endl;   
    std::cout << "Deleted such items: " << deletedCount << std::endl;

    return 0;
}