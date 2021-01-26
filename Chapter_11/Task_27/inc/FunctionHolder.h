#ifndef FUNCTION_HOLDER_H
#define FUNCTION_HOLDER_H

#include <vector>

typedef void (*dummyFunc_t)();

class FunctionHolder
{
private:
    std::vector<dummyFunc_t> m_funcHolder;

public:
    void add(dummyFunc_t funcPtr);
    void remove(dummyFunc_t funcPtr);
    void run();
};

#endif // FUNCTION_HOLDER_H