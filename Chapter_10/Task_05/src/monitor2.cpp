#include "../inc/Monitor.h"
#include "../inc/Monitor2.h"

Monitor2::Monitor2(Monitor *monitor)
{
    m_monitor = monitor;

    m_monitor->incident();
    m_monitor->print();
}

Monitor2::~Monitor2()
{
    m_monitor->decrement();
    m_monitor->print();

    delete m_monitor;
}