#ifndef MOUSE_H
#define MOUSE_H

#include <iostream>
#include "Rodent.h"

class Mouse : public Rodent
{
public:
    void gnaw() const;
    void move() const;
    void hide() const;
    void squeak() const;
};

inline void Mouse::gnaw() const { std::cout << "Nom nom, delicious cheese.\n"; }
inline void Mouse::move() const { std::cout << "Searching for cheese...\n"; }
inline void Mouse::hide() const { std::cout << "Oh no, the cat is here. Everyone hide!!\n"; }
inline void Mouse::squeak() const { std::cout << "Squeak squeak I am a happy Mouse.\n"; }

#endif // MOUSE_H