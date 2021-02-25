#include <iostream>
#include <fstream>
#include <string>
#include "../inc/MemStash.h"

int main()
{
    MemStash intStash(sizeof(int));

    for (int i = 0; i < 100; i++)
    {
        intStash.add(&i);
    }

    for (int j = 0; j < intStash.count(); j++)
    {
        std::cout << "intStash.fetch(" << j << ") = "
                  << *(int *)intStash.fetch(j)
                  << std::endl;
    }

    const int bufsize = 80;

    MemStash stringStash(sizeof(char) * bufsize, 100);

    std::ifstream in("Stash3Test.cpp");
    std::string line;

    while (getline(in, line))
    {
        stringStash.add((char *)line.c_str());
    }

    int k = 0;
    char *cp;

    while ((cp = (char *)stringStash.fetch(k++)) != 0)
    {
        std::cout << "stringStash.fetch(" << k << ") = "
                  << cp << std::endl;
    }

    return 0;
}