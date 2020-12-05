#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../inc/Stash.h"
#include "../inc/Stack.h"

int main()
{
    const int MAX_WORD_LENGTH = 30; // in bytes

    std::ifstream file("../inc/dummy.txt");
    std::string entry;
    std::vector<std::string> lines;

    Stack stack;
    stack.initialize();

    while (getline(file, entry))
    {
        lines.push_back(entry);
    }

    Stash *p_stringStash;
    std::istringstream line;

    for (int i = lines.size() - 1; i >= 0; i--)
    {
        p_stringStash = new Stash;
        p_stringStash->initialize(MAX_WORD_LENGTH);

        line.str(lines[i]);

        while (line >> entry)
        {
            p_stringStash->add(entry.c_str());
        }

        line.clear();
        stack.push(p_stringStash);
    }

    while ((p_stringStash = (Stash *)stack.pop()) != 0)
    {
        for (int i = 0; i < p_stringStash->count(); i++)
        {
            std::cout << (char *)p_stringStash->fetch(i) << " ";
        }

        std::cout << std::endl;

        delete p_stringStash;
    }

    stack.cleanup();

    return 0;
}
