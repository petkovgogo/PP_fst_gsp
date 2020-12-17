#include "../inc/Stash.h"
#include "../inc/Hen.h"

int main()
{
    const int HEN_COUNT = 8;

    Stash henStash;
    henStash.initialize(sizeof(Hen));

    for (int i = 0; i < HEN_COUNT; i++)
    {
        henStash.add(new Hen);
    }

    Hen *hen;
    for (int i = 0; i < henStash.count(); i++)
    {
        hen = (Hen *)henStash.fetch(i);

        hen->display();
    }

    henStash.cleanup();

    return 0;
}
