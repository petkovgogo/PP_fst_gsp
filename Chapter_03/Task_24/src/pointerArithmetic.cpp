#include <iostream>

#define SIZE 10
#define P(EX) std::cout << #EX << ": " << EX << std::endl;

int main()
{
    long longArr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        longArr[i] = i; // Give it index values
    }

    long *lptr = longArr;
    P(*lptr);
    P(*++lptr);
    P(*(lptr + 5));

    long *lptr2 = lptr + 5;
    P(*lptr2);
    P(*(lptr2 - 4));
    P(*--lptr2);
    P(lptr2 - lptr); // Yields number of elements

    std::cout << std::endl;

    double doubleArr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        longArr[i] = i; // Give it index values
    }

    double *dptr = doubleArr;
    P(*dptr);
    P(*++dptr);
    P(*(dptr + 5));

    double *dptr2 = dptr + 5;
    P(*dptr2);
    P(*(dptr2 - 4));
    P(*--dptr2);
    P(dptr2 - dptr); // Yields number of elements

    return 0;
}