#include <fstream>
#include <sstream>
#include <string>
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
    std::string entry;
    std::vector<std::string> lines;

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
        m_stack.push(p_stringStash);
    }
}

Stash *StashStack::pop()
{
    return (Stash *)m_stack.pop();
}

void StashStack::cleanup()
{
    m_stack.cleanup();
}
