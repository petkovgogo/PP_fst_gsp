#include <iostream>

class CopyCat
{
public:
    CopyCat() {}
    CopyCat(const CopyCat &)
    {
        std::cout << "Using CopyCat copy-constructor ";
    }
};

void passedArgumentCC(CopyCat)
{
    std::cout << "after passing by value." << std::endl;
}

const CopyCat returnedValueCC()
{
    return CopyCat();
}

int main()
{
    CopyCat copyCat1;

    passedArgumentCC(copyCat1);

    CopyCat copyCat2 = returnedValueCC(); // copy-constructor is not being called (?)

    std::cout << "after returning temporary object." << std::endl;

    passedArgumentCC(copyCat2);

    return 0;
}