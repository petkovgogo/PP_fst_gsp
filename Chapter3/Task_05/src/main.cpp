#include <iostream>

#define EVALUATE(EXP) \
{\
    std::cout << "A = " << #EXP << std::endl; \
    std::cout << "A = " << EXP << std::endl; \
}


int main()
{
    //Слагам имената x, y и z на променливите, защото изразите (стр 159 - 160 на PDF-a) са математически
    int x = 1;
    int y = 2;
    int z = 3;

    EVALUATE(x + y - 2/2 + z);
    EVALUATE(x + (y - 2) / (2 + z));
    
    return 0;
}