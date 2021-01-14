#include <iostream>

int getNext(const int arr[] = 0)
{
    static const int *storage;

    if (arr)
    {
        storage = arr;
    }

    if (*storage == -1)
    {
        return *storage;
    }
    
    return *storage++;
}

int main()
{
    const int arr[] = {1, 2, 3, 4, 5, -1};

    int val = getNext(arr);

    while (val != -1)
    {
        std::cout << val << " ";
        val = getNext();
    }
    
    std::cout << std::endl;
    
    return 0;
}