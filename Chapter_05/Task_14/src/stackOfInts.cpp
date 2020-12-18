#include <iostream>
#include <vector>
#include "../inc/StackOfInts.h"

/*
class StackImp
{
public:
    int m_arr[STACK_CAPACITY];
    int m_currElementIndex;

    StackImp();
    ~StackImp();
};

StackImp::StackImp()
{
    m_currElementIndex = 0;
}

StackImp::~StackImp() {}

StackOfInts::StackOfInts()
{
    m_stack = new StackImp;
}

StackOfInts::~StackOfInts()
{
    delete m_stack;
}

void StackOfInts::push(int value)
{
    if (m_stack->m_currElementIndex < STACK_CAPACITY)
    {
        m_stack->m_arr[m_stack->m_currElementIndex++] = value;
    }
    else
    {
        std::cout << "The stack has reached its max capacity" << std::endl;
    }
}

int StackOfInts::peek()
{
    if (m_stack->m_currElementIndex == STACK_CAPACITY)
    {
        return m_stack->m_arr[m_stack->m_currElementIndex - 1];
    }

    return m_stack->m_arr[m_stack->m_currElementIndex];
}

int StackOfInts::pop()
{
    if (m_stack->m_currElementIndex == -1)
    {
        return 0;
    }

    if (m_stack->m_currElementIndex == STACK_CAPACITY)
    {
        m_stack->m_currElementIndex--;
    }

    return m_stack->m_arr[m_stack->m_currElementIndex--];
}

void StackOfInts::cleanup()
{
    if (m_stack->m_currElementIndex != -1)
    {
        std::cout << "Stack is not empty" << std::endl;
    }
}
*/

class StackImp
{
public:
    std::vector<int> m_intVector;
};

StackOfInts::StackOfInts()
{
    m_stack = new StackImp;
}

StackOfInts::~StackOfInts()
{
    delete m_stack;
}

void StackOfInts::push(int value)
{
    if (m_stack->m_intVector.size() < STACK_CAPACITY)
    {
        m_stack->m_intVector.push_back(value);
    }
    else
    {
        std::cout << "The stack has reached its max capacity" << std::endl;
    }
}

int StackOfInts::peek()
{
    return m_stack->m_intVector[m_stack->m_intVector.size() - 1];
}

int StackOfInts::pop()
{
    if (m_stack->m_intVector.size() == 0)
    {
        return 0;
    }

    int result = m_stack->m_intVector[m_stack->m_intVector.size() - 1];
    m_stack->m_intVector.pop_back();

    return result;
}

void StackOfInts::cleanup()
{
    if (!m_stack->m_intVector.empty())
    {
        std::cout << "Stack is not empty" << std::endl;
    }
}