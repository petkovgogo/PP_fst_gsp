#include "../inc/Person.h"

int main()
{
    const int AGE = 17;

    Person person;
    setAge(person, AGE);

    printAge(person);

    return 0;
}
