#include "../inc/Dog.h"

const Dog &modify(const Dog *dog)
{
    // dog->changeSound("Ruff Ruff"); // error: using non-const function on const object
    dog->sniff();

    return *dog;
}

Dog &modify(Dog &dog)
{
    dog.changeSound("Ruff Ruff");
    dog.sniff();

    return dog;
}

int main()
{
    Dog dog;

    const Dog &constDogRef = modify(&dog);
    constDogRef.bark();

    modify(dog).bark();
    dog.bark(); // sound is changed via reference

    return 0;
}