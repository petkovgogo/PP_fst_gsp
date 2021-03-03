#include <iostream>

template <class T>
T fibonacci(int n)
{
    const int sz = 100;
    static T f[sz]; // Initialized to zero

    f[0] = f[1] = 1;

    // Scan for unfilled array elements:
    int i;

    for (i = 0; i < sz; i++)
    {
        if (f[i] == 0)
        {
            break;
        }
    }

    while (i <= n)
    {
        f[i] = f[i - 1] + f[i - 2];
        i++;
    }

    return f[n];
}

#define PRINT(EXP)            \
    std::cout << #EXP " -> "; \
    printSize(EXP);

template <class T>
void printSize(T element)
{
    std::cout << "Value: " << element << ". Size of the element: " << sizeof(element) << std::endl;
}

int main()
{
    PRINT(fibonacci<int>(7));
    PRINT(fibonacci<long>(51));
    PRINT(fibonacci<float>(12));
    PRINT(fibonacci<double>(28));

    return 0;
}