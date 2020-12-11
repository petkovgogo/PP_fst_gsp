#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../inc/Stash.h"
#include "../inc/Stack.h"

void inputData(Stack &stack)
{
    const int MAX_ROW_LENGTH = 200; // in bytes

    std::ifstream file("../inc/dummy.txt");
    std::string entry;
    std::vector<std::string> lines;

    while (getline(file, entry))
    {
        lines.push_back(entry);
    }

    Stash *p_stringStash;

    for (int i = lines.size() - 1; i >= 0; i -= 5)
    {
        p_stringStash = new Stash;
        p_stringStash->initialize(MAX_ROW_LENGTH);

        for (int j = i; (j >= 0) && (j > i - 5); j--)
        {
            p_stringStash->add(lines[j].c_str());
        }

        stack.push(p_stringStash);
    }
}

void printStack(Stack &stack)
{
    Stash *p_stringStash;

    while ((p_stringStash = (Stash *)stack.pop()) != 0)
    {
        for (int i = p_stringStash->count() - 1; i >= 0; i--)
        {
            std::cout << (char *)p_stringStash->fetch(i) << std::endl;
        }

        delete p_stringStash;
    }
}

int main()
{

    Stack stack;
    stack.initialize();

    inputData(stack);
    printStack(stack);

    stack.cleanup();

    return 0;
}
