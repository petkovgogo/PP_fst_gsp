#include <iostream>

class CopyCat
{
public:
    CopyCat() {}
    CopyCat(CopyCat &cc)
    {
        std::cout << "Using CopyCat copy-constructor ";
    }
};

void passedArgumentCC(CopyCat copyCat)
{
    std::cout << "after passing by value." << std::endl;
}

CopyCat &returnedValueCC()
{
    CopyCat copyCat;

    return copyCat;
}

int main()
{
    CopyCat copyCat1;

    passedArgumentCC(copyCat1);

    CopyCat copyCat2 = returnedValueCC();

    std::cout << "after returning temporary object." << std::endl;

    return 0;
}