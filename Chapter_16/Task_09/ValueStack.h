#ifndef VALUESTACK_H
#define VALUESTACK_H

#include <iostream>
#include <algorithm>

template <class T, int initSize = 10>
class Stack
{
private:
    T *m_stack;
    size_t m_top;
    size_t m_quantity;
    int m_incrVal;

    void inflate()
    {
        if (m_top == m_quantity)
        {
            T *newStorage = new T[m_quantity + m_incrVal];

            std::copy(m_stack, m_stack + m_quantity, newStorage);

            delete[] m_stack;

            m_stack = newStorage;
            m_quantity += m_incrVal;
            m_incrVal *= 2;

            std::cout << "Size increased to " << m_quantity << std::endl;
        }
    }

public:
    Stack() : m_stack(new T[initSize]), m_top(0), m_quantity(initSize), m_incrVal(initSize) {}

    void push(const T &x)
    {
        inflate();
        m_stack[m_top++] = x;
    }

    T peek() const { return m_stack[m_top - 1]; }

    T pop()
    {
        return m_stack[--m_top];
    }
};

#endif // VALUESTACK_H