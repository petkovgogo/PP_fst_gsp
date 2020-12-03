#include "../inc/Person.h"

#define AGE 17

int main()
{
    Person person;
    setAge(person, AGE);

    printAge(person);

    return 0;
}
