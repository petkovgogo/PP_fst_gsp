#include <iostream>

class Monitor
{
    static int m_incidents;

public:
    void incident() { m_incidents++; }
    void print() { std::cout << "Incidents: " << m_incidents << std::endl; }
};

int Monitor::m_incidents = 0;

void incidentHappens()
{
    static Monitor monitor;

    monitor.incident();
    monitor.print();
}

int main()
{
    const int COUNT = 7;

    for (int i = 0; i < COUNT; i++)
    {
        incidentHappens();
    }

    return 0;
}