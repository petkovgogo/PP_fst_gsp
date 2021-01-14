#ifndef MONITOR_2_H
#define MONITOR_2_H

#include "Monitor.h"

class Monitor2
{
    Monitor *m_monitor;

public:
    Monitor2(Monitor *monitor);
    ~Monitor2();
};

#endif // MONITOR_2_H