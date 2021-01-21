#include "../inc/Mirror.h"

Mirror::Mirror()
{
    m_mirror = 0;
    m_state = true;
}

Mirror::Mirror(Mirror &mirror)
{
    m_mirror = &mirror;
    m_state = false;
}

bool Mirror::test() const
{
    if (m_mirror == 0)
    {
        return m_state;
    }

    return m_mirror->test();
}