#include "../inc/BirdHouse.h"

#include <iostream>

BirdHouse::BirdHouse(Bird birdObj, Bird *birdPtr, Bird &birdRef)
    : m_birdObj(birdObj), m_birdPtr(birdPtr), m_birdRef(birdRef) {}

std::ostream &operator<<(std::ostream &out, BirdHouse &house)
{
    out << "\nObject: " << house.m_birdObj
        << "\nPointer: " << *house.m_birdPtr
        << "\nReference: " << house.m_birdRef;

    return out;
}