#include "../inc/StringHolder.h"

#include <iostream>
#include <string>

StringHolder::StringHolder(std::string text)
{
    m_text = text;
}

void StringHolder::print() const
{
    std::cout << m_text << " ";
}