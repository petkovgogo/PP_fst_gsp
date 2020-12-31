#include <iostream>

int main()
{
    double arr[] = {3.14, 2.71, 6.63};

    double *const pArr = arr;

    std::cout << *pArr << std::endl;
    //! std::cout << *++pArr << std::endl; // cannot increment
    //! std::cout << *--pArr << std::endl; // cannot decrement
    
    //! pArr = arr + 2; // cannot point to another address (?)

    return 0;
}