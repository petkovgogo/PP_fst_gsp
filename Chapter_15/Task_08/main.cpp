#include <iostream>
#include <vector>
#include "Rodent.h"
#include "Mouse.h"
#include "BlueHamster.h"
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
            rodents.push_back(new BlueHamster); // creating a BlueHamster instead of a Hamster
        }
        else
        {
            rodents.push_back(new Gerbil);
        }

        rodents[i]->squeak(); // No change in the case of a BlueHamster
        rodents[i]->move();   // No change in the case of a BlueHamster
        rodents[i]->gnaw();   // No change in the case of a BlueHamster
        rodents[i]->hide();   // No change in the case of a BlueHamster

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