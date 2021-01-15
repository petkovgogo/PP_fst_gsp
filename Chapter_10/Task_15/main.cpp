#include <iostream>
#include <vector>

#define PRINT(EXP) std::cout << #EXP " = " << EXP << std::endl;

int main()
{
    const int COUNT = 7;

    std::vector<int> numbers;
    register int operand = 7;

    for (int i = 1; i <= COUNT; i++)
    {
        numbers.push_back(i * operand);        
    }

    for (auto i = numbers.begin(); i != numbers.end(); i++)
    {
        std::cout << "\n*i = " << *i << " operand = " << operand << std::endl;
        PRINT(*i + operand);
        PRINT(*i - operand);
        PRINT(*i * operand);
        PRINT(*i / operand);
    }
    
    return 0;
}