#include "Plant.h"
#include "Greenhouse.h"
#include "Carrot.h"
#include "Potato.h"
#include "Tomato.h"

int main()
{
    Carrot carrot(12, 25, 17, 46, regular, normal);
    Potato potato(5, 25, 12, 50, dim, low);
    Tomato tomato(12, 23, 20, 60, bright, high);
    Greenhouse greenhouse(20, 12);

    greenhouse.addPlant(carrot);
    greenhouse.addPlant(potato);
    greenhouse.addPlant(tomato);

    greenhouse.checkRequirements();

    greenhouse.changeTemperature(9);

    greenhouse.checkRequirements();

    greenhouse.removePlant(tomato);
    greenhouse.removePlant(carrot);

    greenhouse.changeLighting(dim);
    greenhouse.changeCO2Level(low);

    greenhouse.checkRequirements();

    greenhouse.removePlant(potato);

    return 0;
}