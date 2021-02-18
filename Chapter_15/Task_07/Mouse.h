#ifndef MOUSE_H
#define MOUSE_H

#include <iostream>
#include "Rodent.h"

class Mouse : public Rodent
{
public:
    void gnaw();
    void move();
    void hide();
    void squeak();
};



inline void Mouse::gnaw() { std::cout << "Nom nom, delicious cheese.\n"; }
inline void Mouse::move() { std::cout << "Searching for cheese...\n"; }
inline void Mouse::hide() { std::cout << "Oh no, the cat is here. Everyone hide!!\n"; }
inline void Mouse::squeak() { std::cout << "Squeak squeak I am a happy Mouse.\n"; }

#endif // MOUSE_H