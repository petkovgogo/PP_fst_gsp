#include <iostream>

class Sumator
{
public:
#ifdef DEFAULT_AGUMENTS

    int sum(int num1 = 0, int num2 = 0, int num3 = 0) { return num1 + num2 + num3; }

#else

    int sum() { return 0; }
    int sum(int num1) { return num1; }
    int sum(int num1, int num2) { return num1 + num2; }
    int sum(int num1, int num2, int num3) { return num1 + num2 + num3; }

#endif // DEFAULT_AGUMENTS
};

int main() // It doesn't matter if DEFAULT_AGUMENTS is defined. The main funcion doesn't change
{
    const int NUM1 = 1;
    const int NUM2 = 2;
    const int NUM3 = 3;

    Sumator sumator;

    std::cout << sumator.sum() << std::endl;
    std::cout << sumator.sum(NUM1) << std::endl;
    std::cout << sumator.sum(NUM1, NUM2) << std::endl;
    std::cout << sumator.sum(NUM1, NUM2, NUM3) << std::endl;

    return 0;
}
