#ifndef AUTOCOUNTER_H
#define AUTOCOUNTER_H

#include <iostream>
#include <set> // Standard C++ Library container
#include <cstring>
#include <cassert>

class AutoCounter
{
private:
    static const int BUF_SIZE = 50;
    static int count;
    int m_id;
    char *const m_name;

    class CleanupCheck
    {
    private:
        std::set<AutoCounter *> trace;

    public:
        void add(AutoCounter *ap)
        {
            trace.insert(ap);
        }

        void remove(AutoCounter *ap)
        {
            assert(trace.erase(ap) == 1);
        }

        ~CleanupCheck()
        {
            std::cout << "~CleanupCheck()" << std::endl;
            assert(trace.size() == 0);
        }
    };

    static CleanupCheck verifier;

    // Prevent assignment and copy-construction:
    AutoCounter(const AutoCounter &);
    void operator=(const AutoCounter &);

public:
    AutoCounter(const char *name) : m_id(count++), m_name(new char[BUF_SIZE])
    {
        strcpy(m_name, name);

        verifier.add(this); // Register itself

        std::cout << "created AutoCounter #" << m_id << " for "
                  << m_name
                  << std::endl;
    }

    ~AutoCounter()
    {
        std::cout << "destroying AutoCounter #" << m_id
                  << " for "
                  << m_name
                  << std::endl;

        verifier.remove(this);

        delete[] m_name;
    }

    const char *getName() { return m_name; }

    friend std::ostream &operator<<(std::ostream &os, const AutoCounter &ac)
    {
        return os << "AutoCounter for " << ac.m_name;
    }
};

AutoCounter::CleanupCheck AutoCounter::verifier;
int AutoCounter::count;

#endif // AUTOCOUNTER_H