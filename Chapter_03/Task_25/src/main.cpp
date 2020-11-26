#include <iostream>

void printBinary(const unsigned char val)
{
    for (int i = 7; i >= 0; i--)
    {
        if (val & (1 << i))
        {
            std::cout << "1";
        }
        else
        {
            std::cout << "0";
        }
    }
}

int main()
{
    float number = 3.14;

    unsigned char ch = reinterpret_cast<unsigned char>(&number);
    unsigned char *cPtr = &ch;

    for (int i = 0; i < sizeof(float); i++)
    {
        printBinary(cPtr[i]);
        std::cout << std::endl;
    }

    std::cout << std::endl;
    number = 6.63;
    ch = reinterpret_cast<unsigned char>(&number);
    cPtr = &ch;

    for (int i = 0; i < sizeof(float); i++)
    {
        printBinary(cPtr[i]);
        std::cout << std::endl;
    }

    return 0;
}
