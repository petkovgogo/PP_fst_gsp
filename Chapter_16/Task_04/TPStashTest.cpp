#include <iostream>
#include <fstream>
#include <string>
#include "TPStash.h"

int main()
{
    PStash<int> intStash;

    for (int i = 0; i < 25; i++)
    {
        intStash.add(new int(i));
    }
    
    for (int j = 0; j < intStash.count(); j++)
    {
        std::cout << "intStash[" << j << "] = "
             << *(int *)intStash[j] << std::endl;
    }

    // Clean up:
    for (int k = 0; k < intStash.count(); k++)
    {
        delete intStash.remove(k);
    }

    std::ifstream in("TPStashTest.cpp");

    PStash<std::string> stringStash;
    std::string line;

    while (getline(in, line))
    {
        stringStash.add(new std::string(line));
    }
    
    // Print out the strings:
    for (int u = 0; stringStash[u]; u++)
    {
        std::cout << "stringStash[" << u << "] = "
             << *(std::string *)stringStash[u] << std::endl;
    }
    
    // Clean up:
    for (int v = 0; v < stringStash.count(); v++)
    {
        delete (std::string *)stringStash.remove(v);
    }

    return 0;
}