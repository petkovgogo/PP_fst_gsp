#include <iostream>

int increment(int num) { return ++num; }

int main()
{
    int initialValue = 41;
    int num = increment(initialValue);

    std::cout << "Number: " << num << std::endl;

    return 0;
}