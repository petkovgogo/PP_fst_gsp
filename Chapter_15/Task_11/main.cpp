#include "Aeroplane.h"
#include "Helicopter.h"
#include "Tower.h"

int main()
{
    Aeroplane ap1;
    Aeroplane ap2;
    Helicopter heli;
    Tower controlTower;

    controlTower.assignAircraft(ap1);
    controlTower.assignAircraft(ap1); // attempt second assignment
    controlTower.assignAircraft(ap2);
    controlTower.assignAircraft(heli);

    controlTower.allowTakeoff(ap1);
    controlTower.allowTakeoff(ap2);

    ap1.fly();
    ap2.fly();

    controlTower.warnAircraft(ap1, ap2);

    controlTower.allowTakeoff(heli);

    heli.fly();

    controlTower.allowLanding(ap1);
    controlTower.allowLanding(ap2);
    controlTower.allowLanding(heli);

    controlTower.unassignAircraft(heli);

    controlTower.allowTakeoff(heli);

    controlTower.unassignAircraft(ap1);
    controlTower.unassignAircraft(ap2);

    return 0;
}