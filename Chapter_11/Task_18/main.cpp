#include <iostream>

class SpecialCC
{
public:
    SpecialCC() {}
    SpecialCC(SpecialCC &original, int secretNum = 42)
    {
        std::cout << "Using SpecialCC copy-constructor. Secret number: "
                  << secretNum << std::endl;
    }
};

void passByValue(SpecialCC copyObject)
{
    std::cout << "Inside passByValue()" << std::endl;
}

int main()
{
    SpecialCC originalObj;

    passByValue(originalObj);

    return 0;
}