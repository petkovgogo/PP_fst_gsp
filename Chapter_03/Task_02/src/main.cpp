#include <iostream>
#include <cmath>

int main()
{
    const int range = 175;
    int numRoot = 0;
    bool isPrime;

    std::cout << "Prime numbers [2; " << range << "]:" << std::endl;
    for (int i = 2; i <= range; i++)
    {
        isPrime = true;
        numRoot = sqrt(i);
        for (int j = 2; j <= numRoot; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            std::cout << " " << i;
        }
    }

    std::cout << std::endl;

    return 0;
}