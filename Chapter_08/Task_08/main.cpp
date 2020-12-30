#include <iostream>

int main()
{
    long arr[] = {42, 415};

    const long* p1Arr = arr;
    long const* p2Arr = arr;

    std::cout << "Printed with 1st pointer: " << p1Arr[0] << std::endl;
    std::cout << "Printed with 2nd pointer: " << p2Arr[1] << std::endl;

    // p1Arr[0] = 7; // error
    // p2Arr[1] = 7; // error

    return 0;
}