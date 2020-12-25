#include "../inc/Simple.h"

int main()
{
    const int NUM1 = 42;
    const int NUM2 = 7;

    Simple simpleArr[] = {
        Simple(NUM1 + NUM2),
        Simple(NUM1 - NUM2),
        Simple(NUM1 * NUM2),
        Simple(NUM1 / NUM2)
    };

    for (int i = 0; i < sizeof(simpleArr) / sizeof(*simpleArr); i++)
    {
        simpleArr[i].printNumber();
    }

    return 0;
}