#include "../inc/StringHolder.h"

StringHolder::StringHolder() :
    first_string("first string"),
    second_string("second string"),
    third_string("third string")
{
    int index = 0;

    init(first_string, first_size, first_index, ++index);
    init(second_string, second_size, second_index, ++index);
    init(third_string, third_size, third_index, ++index);
}

inline void StringHolder::init(
    const char *m_str,
    int &m_size,
    int &m_index,
    int &index
)
{
    m_size = sizeof(m_str) / sizeof(*m_str);
    m_index = index;
}

const char *StringHolder::lookup(int index)
{

    if (index == first_index)
    {
        return first_string;
    }
    else if (index == second_index)
    {
        return second_string;
    }

    return third_string;
}