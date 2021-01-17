#include "../inc/ArrayContainer.h"

#include <iostream>

const int ArrayContainer::m_arr1[] = {0, 1, 2, 3, 4};
int ArrayContainer::m_arr2[] = {5, 6, 7, 8, 9};

void ArrayContainer::printArr1()
{
    const int SIZE = sizeof(m_arr1) / sizeof(*m_arr1);

    std::cout << "Arr1:" << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << m_arr1[i] << " ";
    }

    std::cout << std::endl;
}

void ArrayContainer::printArr2()
{
    const int SIZE = sizeof(m_arr2) / sizeof(*m_arr2);

    std::cout << "Arr2:" << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << m_arr2[i] << " ";
    }

    std::cout << std::endl;
}