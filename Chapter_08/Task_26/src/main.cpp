#include <iostream>
#include "../inc/Quoter.h"

int main()
{
    Quoter q;
    const Quoter cq;

    cq.lastQuote(); // OK
    cq.quote(); // Now OK, because quote() is a const member function
    
    for (int i = 0; i < 20; i++)
    {
        std::cout << q.quote() << std::endl;
    }

    return 0;
}