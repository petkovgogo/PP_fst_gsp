#include "../inc/ArrayHolder.h"

#include <iostream>
#include "../inc/StringHolder.h"

const StringHolder ArrayHolder::m_constHolderArr[] =
{
    StringHolder("Lorem"),
    StringHolder("ipsum") 
};

StringHolder ArrayHolder::m_holderArr[] =
{
    StringHolder("dolor"),
    StringHolder("sit"),
    StringHolder("amet") 
};

void ArrayHolder::printConstArr()
{
    const int SIZE = sizeof(m_constHolderArr) / sizeof(*m_constHolderArr);

    std::cout << "Static const array:" << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        m_constHolderArr[i].print();
    }
    
    std::cout << std::endl;
}

void ArrayHolder::printArr()
{
    const int SIZE = sizeof(m_holderArr) / sizeof(*m_holderArr);
    
    std::cout << "Static array:" << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        m_holderArr[i].print();
    }
    
    std::cout << std::endl;
}