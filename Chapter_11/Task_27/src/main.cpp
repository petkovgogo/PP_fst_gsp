#include <iostream>
#include "../inc/FunctionHolder.h"

// A macro to define dummy functions:
#define DF(N)                                                  \
    void N()                                                   \
    {                                                          \
        std::cout << "function " #N " called..." << std::endl; \
    }

DF(a);
DF(b);
DF(c);
DF(d);
DF(e);
DF(f);
DF(g);

int main()
{
    const int COUNT = 7;

    dummyFunc_t funcTable[COUNT] = {a, b, c, d, e, f, g};
    FunctionHolder funcHolder;

    for (int i = 0; i < COUNT; i++)
    {
        funcHolder.add(funcTable[i]);
    }
    
    funcHolder.run();
    std::cout << std::endl;

    funcHolder.remove(b);
    funcHolder.remove(d);

    funcHolder.run();

    return 0;
}