#include <iostream>
#include "../inc/MyString.h"

MyString::MyString(const char *text)
{
    m_text = text;
}

void MyString::printText() const
{
    std::cout << m_text << std::endl;
}