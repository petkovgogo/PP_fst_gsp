#include <iostream>
#include "../inc/MultiFunctional.h"
#include "../inc/FunctionHolder.h"

int main()
{
    const int COUNT = 7;

    m_funcPtr_t funcTable[COUNT] = {
        &MultiFunctional::a,
        &MultiFunctional::b,
        &MultiFunctional::c,
        &MultiFunctional::d,
        &MultiFunctional::e,
        &MultiFunctional::f,
        &MultiFunctional::g
    };

    MultiFunctional multiFunc;
    FunctionHolder funcHolder(multiFunc);

    for (int i = 0; i < COUNT; i++)
    {
        funcHolder.add(funcTable[i]);
    }

    funcHolder.run();
    std::cout << std::endl;

    funcHolder.remove(&MultiFunctional::b);
    funcHolder.remove(&MultiFunctional::d);
    funcHolder.run();

    return 0;
}