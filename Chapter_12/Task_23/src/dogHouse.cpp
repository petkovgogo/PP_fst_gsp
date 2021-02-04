#include <iostream>
#include <string>
#include "../inc/DogHouse.h"
#include "../inc/Dog.h"

int DogHouse::instances = 0;

DogHouse::DogHouse(Dog *dog, const std::string &house) : m_id(++instances), m_dogPtr(dog), m_houseName(house)
{
    std::cout << "Created DogHouse: " << *this << std::endl;
}

DogHouse::DogHouse(const DogHouse &dh)
    : m_id(++instances),
      m_dogPtr(dh.m_dogPtr),
      m_houseName("copy-constructed " + dh.m_houseName)
{
    m_dogPtr->attach();
    std::cout << "DogHouse copy-constructor: " << *this << std::endl;
}

DogHouse &DogHouse::operator=(const DogHouse &dh)
{
    // Check for self-assignment:
    if (&dh != this)
    {
        const_cast<int &>(m_id) = ++instances;

        m_houseName = dh.m_houseName + " assigned";
        // Clean up what you're using first:
        m_dogPtr->detach();
        m_dogPtr = dh.m_dogPtr; // Like copy-constructor
        m_dogPtr->attach();
    }

    std::cout << "DogHouse operator= : " << *this << std::endl;

    return *this;
}

DogHouse::~DogHouse()
{
    std::cout << "DogHouse destructor: " << *this << std::endl;
    m_dogPtr->detach();
}

void DogHouse::renameHouse(const std::string &newName)
{
    m_houseName = newName;
}

void DogHouse::unalias() { m_dogPtr = m_dogPtr->unalias(); }

void DogHouse::renameDog(const std::string &newName)
{
    unalias();
    m_dogPtr->rename(newName);
}

Dog *DogHouse::getDog()
{
    unalias();

    return m_dogPtr;
}

std::ostream &operator<<(std::ostream &os, const DogHouse &dh)
{
    return os << "[" << dh.m_houseName << "], "
              << "dog house instance #" << dh.m_id << ", contains " << *dh.m_dogPtr;
}