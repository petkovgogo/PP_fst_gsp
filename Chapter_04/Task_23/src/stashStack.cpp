#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include "../inc/StashStack.h"
#include "../inc/Stack.h"
#include "../inc/Stash.h"

const int MAX_WORD_LENGTH = 30; // in bytes

StashStack::StashStack()
{
    m_stack.initialize();
}

void StashStack::push(Stash *element)
{
    m_stack.push(element);
}

void StashStack::push(std::ifstream &file)
{
    const int MAX_ROW_LENGTH = 200; // in bytes

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

        m_stack.push(p_stringStash);
    }
}

const char *StashStack::pop()
{
    Stash *p_stringStash = (Stash *)m_stack.pop();
    
    if (p_stringStash == 0)
    {
        return 0;
    }

    std::string contents;

    for (int i = p_stringStash->count() - 1; i >= 0; i--)
    {
        contents += (char *)p_stringStash->fetch(i);
        contents += "\n";
    }

    char *data = new char[contents.size()];

    strcpy(data, contents.c_str());
    p_stringStash->cleanup();
    delete p_stringStash;

    return data;
}

void StashStack::cleanup()
{
    m_stack.cleanup();
}
