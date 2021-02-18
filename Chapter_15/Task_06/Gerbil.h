#ifndef GERBIL_H
#define GERBIL_H

#include <iostream>
#include "Rodent.h"

class Gerbil : public Rodent
{
public:
    void gnaw() const;
    void move() const;
    void hide() const;
    void squeak() const;
};

inline void Gerbil::gnaw() const { std::cout << "Nom nom, those pumpkin seeds are quite tasty.\n"; }
inline void Gerbil::move() const { std::cout << "Searching for seeds...\n"; }
inline void Gerbil::hide() const { std::cout << "Is that a snake? Everyone hide!!\n"; }
inline void Gerbil::squeak() const { std::cout << "Squeak squeak I am a happy Gerbil.\n"; }

#endif // GERBIL_H