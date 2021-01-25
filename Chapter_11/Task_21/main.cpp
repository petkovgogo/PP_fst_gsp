#include <iostream>

#define PIVATE_CC

class Simple
{
#ifdef PIVATE_CC

private:
    Simple(Simple &simpleObj) {}

public:
    Simple() {}

#endif // PIVATE_CC
};

void passByValue(Simple simpleObj)
{
    std::cout << "Object was passed by value." << std::endl;
}

int main()
{
    Simple simpleObj;

    passByValue(simpleObj);

    return 0;
}