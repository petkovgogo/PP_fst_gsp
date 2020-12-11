#include <fstream>
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

Stash *StashStack::pop()
{
    return (Stash *)m_stack.pop();
}

void StashStack::cleanup()
{
    m_stack.cleanup();
}
