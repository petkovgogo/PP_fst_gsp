#ifndef MULTI_FUNCTIONAL_H
#define MULTI_FUNCTIONAL_H

#include <iostream>

#define DF(N)                                                  \
    void N()                                                   \
    {                                                          \
        std::cout << "function " #N " called..." << std::endl; \
    }

class MultiFunctional
{
public:
    DF(a);
    DF(b);
    DF(c);
    DF(d);
    DF(e);
    DF(f);
    DF(g);
};

#endif // MULTI_FUNCTIONAL_H