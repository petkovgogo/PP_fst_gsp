#include <iostream>
#include <vector>
#include "Rodent.h"
#include "Mouse.h"
#include "Hamster.h"
#include "Gerbil.h"

int main()
{
    const int COUNT = 25;
    std::vector<Rodent *> rodents;

    for (int i = 0; i < COUNT; i++)
    {
        if (i % 5 == 0)
        {
            rodents.push_back(new Mouse);
        }
        else if (i % 2 == 0)
        {
            rodents.push_back(new Hamster);
        }
        else
        {
            rodents.push_back(new Gerbil);
        }

        rodents[i]->squeak();
        rodents[i]->move();
        rodents[i]->gnaw();
        rodents[i]->hide();

        std::cout << std::endl;
    }

    for (size_t i = 0; i < rodents.size(); i++)
    {
        delete rodents[i];
        rodents[i] = 0;
    }

    rodents.clear();

    return 0;
}