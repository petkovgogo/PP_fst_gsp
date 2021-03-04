#include <iostream>
#include <fstream>
#include <string>
#include "TStack2.h"

int main()
{
    std::ifstream file("TStack2Test.cpp");
    Stack<std::string> textlines;

    // Read file and store lines in the Stack:
    std::string line;

    while (getline(file, line))
    {
        textlines.push(new std::string(line));
    }

    int i = 0;

    // Use iterator to print lines from the list:
    Stack<std::string>::iterator it = textlines.begin();
    Stack<std::string>::iterator *it2 = 0;

    while (it != textlines.end())
    {
        std::cout << it->c_str() << std::endl;
        it++;
        if (++i == 2) // Remember 10th line
        {
            it2 = new Stack<std::string>::iterator(it);
        }
    }

    std::cout << (*it2)->c_str() << std::endl;

    delete it2;

    return 0;
}