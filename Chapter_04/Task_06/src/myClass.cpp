#include <iostream>
#include <random>
#include "../inc/MyClass.h"

int MyClass::updateSecretNumber()
{
    srand (time(NULL));
    return rand() % 10000 + 1000;
}

void MyClass::printNewSecretNumber()
{
    this->m_secretNumber = this->updateSecretNumber();
    std::cout << "The new secret number is: " << this->m_secretNumber << std::endl;
}