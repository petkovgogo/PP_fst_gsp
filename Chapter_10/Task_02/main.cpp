#include <iostream>

int nextFibonacciNumber(bool reset = false)
{
    static int firstNum = 0;
    static int secondNum = 1;
    static int nextNum;

    if (reset)
    {
        firstNum = 0;
        secondNum = 1;
    }

    nextNum = firstNum + secondNum;
    firstNum = secondNum;
    secondNum = nextNum;

    return nextNum;
}

void printFibonacci(const int COUNT)
{
    int nextNum = nextFibonacciNumber(true);

    for (int i = 0; i < COUNT; i++)
    {
        std::cout << nextNum << " ";
        nextNum = nextFibonacciNumber();
    }

    std::cout << std::endl;
}

int main()
{
    const int COUNT = 7;

    printFibonacci(COUNT);
    printFibonacci(COUNT * 2);

    return 0;
}