#include <iostream>
#include <math.h>

#define RANGE 175

int main()
{
    bool isPrime = true;

    std::cout << "Prime numbers [2; " << RANGE << "]:" << std::endl;
    for (int i = 2; i <= RANGE; i++)
    {
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
            }
        }

        if (isPrime)
        {
            std::cout << " " << i;
        }
        else
        {
            isPrime = true;
        }
    }

    return 0;
}