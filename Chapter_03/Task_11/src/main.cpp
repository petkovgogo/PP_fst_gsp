#include <iostream>

int main()
{
    double i, j;

    std::cout << "Enter an double: ";
    std::cin >> i;
    std::cout << "Enter another double: ";
    std::cin >> j;
    
    std::cout << "i > j is " << (i > j) << std::endl;
    std::cout << "i < j is " << (i < j) << std::endl;
    std::cout << "i >= j is " << (i >= j) << std::endl;
    std::cout << "i <= j is " << (i <= j) << std::endl;
    std::cout << "i == j is " << (i == j) << std::endl;
    std::cout << "i != j is " << (i != j) << std::endl;
    std::cout << "i && j is " << (i && j) << std::endl;
    std::cout << "i || j is " << (i || j) << std::endl;
    std::cout << " (i < 10) && (j < 10) is "
              << ((i < 10) && (j < 10)) << std::endl;

    return 0;
}