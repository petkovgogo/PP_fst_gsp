#include "../inc/Person.h"

#define AGE 17

int main()
{
    Person person;
    person.setAge(AGE);

    person.printAge();

    return 0;
}
