#include "../inc/MyString.h"
#include <iostream>
#include <cstring>

MyString::MyString()
{
    m_buf = 0;
}

MyString::MyString(const char *str)
{
    m_buf = new Mem(strlen(str) + 1);
    strcpy((char *)m_buf->pointer(), str);
}

void MyString::concat(const char *str)
{
    if (!m_buf)
    {
        m_buf = new Mem;
    }

#ifdef FIXED_EXAMPLE

    byte *&testPtr = m_buf->pointer();

#else

    byte *testPtr = m_buf->pointer();

#endif // FIXED_EXAMPLE

    strcat((char *)m_buf->pointer(m_buf->msize() + strlen(str) + 1), str);

    std::cout << testPtr << std::endl;
}

void MyString::print(std::ostream &os)
{
    if (!m_buf)
    {
        return;
    }

    os << m_buf->pointer() << std::endl;
}

MyString::~MyString() { delete m_buf; }
