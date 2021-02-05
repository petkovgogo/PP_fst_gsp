#include <iostream>
#include <cstdlib>
#include <new>
#include <sys/time.h>
#include <sys/resource.h>

int count = 0;
const int ALLOC_COUNT = 1000;

void out_of_memory()
{
    std::cerr << "memory exhausted after " << count
              << " allocations! This equals " << count * ALLOC_COUNT * sizeof(int)
              << " bytes." << std::endl;

    exit(1);
}

int main()
{
    const rlim_t HEAP_LIMIT = 2147483648; // 2 GB

    struct rlimit limit;
    limit.rlim_cur = HEAP_LIMIT;
    limit.rlim_max = HEAP_LIMIT;

    // sets the max heap size, so the computer doesn't run out of resourses (and so I don't have to wait until ~8 GB RAM and ~4 GB swap run out)
    // if the limit is not set, the process is eventually killed by the OS
    setrlimit(RLIMIT_DATA, &limit);

    std::set_new_handler(out_of_memory);

    while (true)
    {
        new int[ALLOC_COUNT]; // Exhausts memory
        count++;
    }

    return 0;
}