#include "../inc/FunctionHolder.h"

#include <vector>

FunctionHolder::FunctionHolder(MultiFunctional &origin) : m_mfObj(origin) {}

void FunctionHolder::add(m_funcPtr_t funcPtr)
{
    m_funcHolder.push_back(funcPtr);
}

void FunctionHolder::remove(m_funcPtr_t funcPtr)
{
    for (int i = 0; i < m_funcHolder.size(); i++)
    {
        if (m_funcHolder[i] == funcPtr)
        {
            m_funcHolder.erase(m_funcHolder.begin() + i);
            return;
        }
    }
}

void FunctionHolder::run()
{
    for (auto it = m_funcHolder.begin(); it != m_funcHolder.end(); it++)
    {
        (m_mfObj.**it)();
    }
}