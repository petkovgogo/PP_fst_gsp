#include <iostream>
#include "../inc/Monitor.h"

int Monitor::m_incidents = 0;

void Monitor::incident()
{
    m_incidents++;
}

void Monitor::decrement()
{
    if (m_incidents > 0)
    {
        m_incidents--;   
    }
}

void Monitor::print()
{
    std::cout << "Incidents: " << m_incidents << std::endl;
}