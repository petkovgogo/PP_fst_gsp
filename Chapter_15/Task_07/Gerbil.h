#ifndef GERBIL_H
#define GERBIL_H

#include <iostream>
#include "Rodent.h"

class Gerbil : public Rodent
{
public:
    void gnaw();
    void move();
    void hide();
    void squeak();
};



inline void Gerbil::gnaw() { std::cout << "Nom nom, those pumpkin seeds are quite tasty.\n"; }
inline void Gerbil::move() { std::cout << "Searching for seeds...\n"; }
inline void Gerbil::hide() { std::cout << "Is that a snake? Everyone hide!!\n"; }
inline void Gerbil::squeak() { std::cout << "Squeak squeak I am a happy Gerbil.\n"; }

#endif // GERBIL_H