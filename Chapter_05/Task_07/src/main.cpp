#include "../inc/Hen.h"

int main()
{
    Hen hen;
    Hen::Nest nest;
    Hen::Nest::Egg egg("white");

    nest.addEgg();

    hen.display(nest);
    nest.display(egg);
    
    return 0;
}
