#ifndef MONITOR_H
#define MONITOR_H

class Monitor
{
    static int m_incidents;

public:
    void incident();
    void decrement();
    void print();
};

#endif // MONITOR_H