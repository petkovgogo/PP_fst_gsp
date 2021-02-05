#include "../inc/Counted.h"
#include "../inc/PStash.h"

int main()
{
    const int COUNT = 7;
    PStash stash;

    for (int i = 0; i < COUNT; i++)
    {
        stash.add(new Counted());
    }

    // Whem the destructor is called, the assertion fails, because the memory is not freed, and the program terminates

#ifdef CLEANUP

    for (int i = 0; i < stash.count(); i++)
    {
        delete (Counted *)stash.remove(i);
    }

#endif // CLEANUP

    return 0;
}