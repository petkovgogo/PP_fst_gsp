#include "../inc/Hen.h"

int main()
{
    Hen hen;
    Hen::Nest nest;
    Hen::Nest::Egg egg;

    hen.display();
    nest.display();
    egg.display();
    
    return 0;
}
