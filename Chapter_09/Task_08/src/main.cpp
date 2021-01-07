#include <iostream>
#include "../inc/Holder.h"

int main()
{
    Holder h;
    Holder::Pointer hp(&h);
    Holder::Pointer hp2(&h);

    for (int i = 0; i < SIZE; i++)
    {
        hp.set(i);
        hp.next();
    }
    
    hp.top();
    hp2.end();

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "hp = " << hp.read() << ", hp2 = " << hp2.read() << std::endl;
        hp.next();
        hp2.previous();
    }

    return 0;
}