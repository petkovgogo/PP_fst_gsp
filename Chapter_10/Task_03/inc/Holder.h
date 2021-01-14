#ifndef HOLDER_H
#define HOLDER_H

#include <iostream>

class Holder
{
    static const int SIZE = 7;
    int m_arr[SIZE];
    const int m_value;
    static int m_num;

public:
    Holder(int value);

    static void printStatic();
    void print();
};

inline Holder::Holder(int value) : m_value(value)
{
    for (int i = 0; i < SIZE; i++)
    {
        m_arr[i] = m_value / (i + 1);
    }
}

inline void Holder::print()
{
    std::cout << "The values in the array:" << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << m_arr[i] << " ";
    }

    printStatic();
}

#endif // HOLDER_H