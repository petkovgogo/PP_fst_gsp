#include <iostream>
#include <cstring>
#include "../inc/StringStack.h"
#include "../inc/MyString.h"

StringStack::StringStack()
{
    m_index = 0;
    memset(m_stack, 0, m_size * sizeof(char *));
}

StringStack::~StringStack()
{
    if (*m_stack != 0)
    {
        std::cout << "freeing storage..." << std::endl;
        
        for (int i = 0; i < m_index; i++)
        {
            delete m_stack[i];
        }
        
    }
}

void StringStack::push(MyString *s)
{
    if (m_index < m_size)
    {
        m_stack[m_index++] = s;
    }
}

const MyString *StringStack::pop()
{
    if (m_index > 0)
    {
        MyString *myString = m_stack[--m_index];
        m_stack[m_index] = 0;
        return myString;
    }

    return 0;
}