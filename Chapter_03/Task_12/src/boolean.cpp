#include <iostream>

int main()
{
    int i, j;

    std::cout << "Enter an integer: ";
    std::cin >> i;
    std::cout << "Enter another integer: ";
    std::cin >> j;
    
    std::cout << "i > j is " << (i > j) << std::endl;
    std::cout << "i < j is " << (i < j) << std::endl;
    std::cout << "i >= j is " << (i >= j) << std::endl;
    std::cout << "i <= j is " << (i <= j) << std::endl;
    std::cout << "i == j is " << (i == j) << std::endl;
    std::cout << "i not_eq j is " << (i not_eq j) << std::endl;
    std::cout << "i and j is " << (i and j) << std::endl;
    std::cout << "i or j is " << (i or j) << std::endl;
    std::cout << " (i < 10) and (j < 10) is "
              << ((i < 10) and (j < 10)) << std::endl;

    return 0;
}