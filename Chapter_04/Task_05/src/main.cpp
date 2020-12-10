#include "../inc/Person.h"

int main()
{
    const int AGE = 17;

    Person person;
    person.setAge(AGE);

    person.printAge();

    return 0;
}
