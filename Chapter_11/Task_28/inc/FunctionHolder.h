#ifndef FUNCTION_HOLDER_H
#define FUNCTION_HOLDER_H

#include <vector>
#include "MultiFunctional.h"

typedef void (MultiFunctional::*m_funcPtr_t)();

class FunctionHolder
{
private:
    MultiFunctional &m_mfObj;
    std::vector<m_funcPtr_t> m_funcHolder;

public:
    FunctionHolder(MultiFunctional &origin);
    void add(m_funcPtr_t funcPtr);
    void remove(m_funcPtr_t funcPtr);
    void run();
};

#endif // FUNCTION_HOLDER_H