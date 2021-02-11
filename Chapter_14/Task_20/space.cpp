#include <iostream>

class SpaceShip
{
public:
    void fly() const { std::cout << "Flying..." << std::endl; }
};

class Shuttle : public SpaceShip
{
public:
    void land() const { std::cout << "Landing..." << std::endl; }
};

int main()
{
    Shuttle shuttle;

    shuttle.fly();  // OK, the shuttle is a spaceship
    shuttle.land(); // OK, function of a shuttle

    SpaceShip *ssPtr = &shuttle; // OK, the shuttle is a spaceship (Upcast)

    ssPtr->fly(); // OK, function of a spaceship
    // error: ‘class SpaceShip’ has no member named ‘land’
    // ssPtr->land(); // Not OK - a spaceship is not a shuttle

    return 0;
}