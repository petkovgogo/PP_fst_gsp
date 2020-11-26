#include <iostream>

int main()
{
    int i;
    std::cout << "type a number and 'Enter'" << std::endl;
    std::cin >> i;

    (i > 5) ? std::cout << "It's greater than 5" << std::endl : 
    (i < 5) ? std::cout << "It's less than 5 " << std::endl :
    std::cout << "It's equal to 5 " << std::endl;
    
    std::cout << "type a number and 'Enter'" << std::endl;
    std::cin >> i;

    (i < 10) ?
    (i > 5) ? std::cout << "5 < i < 10" << std::endl :
    std::cout << "i <= 5" << std::endl :
    std::cout << "i >= 10" << std::endl;
}