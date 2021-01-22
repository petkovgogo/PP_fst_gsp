#include "../inc/CargoShip.h"

void transportCopy(CargoShip ship)
{
    ship.load(20);
    ship.printCurrentLoad();
    ship.unload(10);
    ship.printCurrentLoad();
    ship.sail();
}

void transportReference(CargoShip &ship)
{
    ship.load(900);
    ship.printCurrentLoad();
    ship.unload(2000);
    ship.printCurrentLoad();
    ship.sail();
}

void transportConstRef(const CargoShip &ship)
{
    // ship.load(50); // non-const funcntion called
    ship.printCurrentLoad();
    // ship.unload(5); // non-const funcntion called
    ship.sail();
}

int main()
{
    CargoShip ship(2000, 1500);

    transportCopy(ship);
    transportReference(ship);
    transportConstRef(ship);

    return 0;
}