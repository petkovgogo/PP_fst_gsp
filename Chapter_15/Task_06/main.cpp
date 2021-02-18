#include <iostream>
#include "Rodent.h"
#include "Mouse.h"
#include "Hamster.h"
#include "Gerbil.h"

int main()
{
    const int COUNT = 25;
    Rodent *rodents[COUNT];

    for (int i = 0; i < COUNT; i++)
    {
        if (i % 5 == 0)
        {
            rodents[i] = new Mouse;
        }
        else if (i % 2 == 0)
        {
            rodents[i] = new Hamster;
        }
        else
        {
            rodents[i] = new Gerbil;
        }

        rodents[i]->squeak();
        rodents[i]->move();
        rodents[i]->gnaw();
        rodents[i]->hide();

        std::cout << std::endl;
    }

    for (int i = 0; i < COUNT; i++)
    {
        delete rodents[i];
        rodents[i] = 0;
    }

    return 0;
}