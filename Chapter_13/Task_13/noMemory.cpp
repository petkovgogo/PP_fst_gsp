#include <iostream>
#include <cstdlib>
#include <new> // bad_alloc definition
#include <sys/time.h>
#include <sys/resource.h>

#define ALLOC_CHECK

class NoMemory
{
private:
    static const int ALLOC_COUNT = 1000;

    int *m_arr;

public:
    NoMemory() : m_arr((int *)std::malloc(ALLOC_COUNT))
    {
        // std::cout << "NoMemory::NoMemory()" << std::endl;
    }

    void *operator new(size_t size)
    {
        // std::cout << "NoMemory::operator new" << std::endl;

        void *memory = std::malloc(size);

#ifdef ALLOC_CHECK

        if (!memory)
        {
            throw std::bad_alloc();
        }

#endif // ALLOC_CHECK

        return memory;
    }
};

int main()
{
    const rlim_t HEAP_LIMIT = 2147483648; // 2 GB

    struct rlimit limit;
    limit.rlim_cur = HEAP_LIMIT;
    limit.rlim_max = HEAP_LIMIT;

    // sets the max heap size, so the computer doesn't run out of resourses (and so I don't have to wait until ~8 GB RAM and ~4 GB swap run out)
    // if the limit is not set, the process is eventually killed by the OS
    setrlimit(RLIMIT_DATA, &limit);

    NoMemory *nm = 0;

#ifdef ALLOC_CHECK

    try
    {
        while (true)
        {
            nm = new NoMemory;
        }
    }
    catch (std::bad_alloc &)
    {
        std::cerr << "Out of memory exception" << std::endl;
    }

#else

    while (true)
    {
        nm = new NoMemory;
    }

#endif // ALLOC_CHECK

    std::cout << "nm = " << nm << std::endl;

    return 0;
}