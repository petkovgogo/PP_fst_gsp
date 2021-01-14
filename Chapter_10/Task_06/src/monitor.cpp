#include "../inc/Monitor.h"

#include <iostream>

int Monitor::m_incidents = 0;

Monitor::Monitor()
{
    std::cout << "Call of Monitor constructor" << std::endl;
}

Monitor::~Monitor()
{
    std::cout << "Call of Monitor destructor" << std::endl;
}

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