#include "../inc/Stack2.h"
#include "../inc/Hen.h"

int main()
{
    const int HEN_COUNT = 8;

    Stack henStack;
    henStack.initialize();
    
    for (int i = 0; i < HEN_COUNT; i++)
    {
        henStack.push(new Hen);
    }
    
    Hen *hen;

    while ((hen = (Hen *)henStack.pop()) != 0)
    {
        hen->display();

        delete hen;
    }
    
    henStack.cleanup();
    
    return 0;
}
