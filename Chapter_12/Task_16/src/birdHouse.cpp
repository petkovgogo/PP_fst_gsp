#include "../inc/BirdHouse.h"

#include <iostream>

BirdHouse::BirdHouse(const Bird birdObj, Bird *birdPtr, Bird &birdRef)
    : m_birdObj(birdObj), m_birdPtr(birdPtr), m_birdRef(birdRef), m_needsCleanup(false) {}

BirdHouse::BirdHouse(const BirdHouse &bh) : m_birdObj(bh.m_birdObj), m_birdPtr(bh.m_birdPtr), m_birdRef(bh.m_birdRef) {}

BirdHouse::~BirdHouse()
{
    if (m_needsCleanup)
    {
        delete m_birdPtr;
        delete &m_birdRef;
    }
}

const BirdHouse BirdHouse::operator+(const BirdHouse &roperand) const
{
    Bird &ref = *(new Bird(m_birdRef + roperand.m_birdRef));

    return BirdHouse(
        m_birdObj + roperand.m_birdObj,
        new Bird(*m_birdPtr + *roperand.m_birdPtr),
        ref
        );
}

const BirdHouse BirdHouse::operator-(const BirdHouse &roperand) const
{
    Bird &ref = *(new Bird(m_birdRef - roperand.m_birdRef));

    return BirdHouse(
        m_birdObj - roperand.m_birdObj,
        new Bird(*m_birdPtr - *roperand.m_birdPtr),
        ref
        );
}

const BirdHouse BirdHouse::operator*(const BirdHouse &roperand) const
{
    Bird &ref = *(new Bird(m_birdRef * roperand.m_birdRef));

    return BirdHouse(
        m_birdObj * roperand.m_birdObj,
        new Bird(*m_birdPtr * *roperand.m_birdPtr),
        ref
        );
}

const BirdHouse BirdHouse::operator/(const BirdHouse &roperand) const
{
    Bird &ref = *(new Bird(m_birdRef / roperand.m_birdRef));

    return BirdHouse(
        m_birdObj / roperand.m_birdObj,
        new Bird(*m_birdPtr / *roperand.m_birdPtr),
        ref
        );
}

std::ostream &operator<<(std::ostream &out, const BirdHouse &house)
{
    out << "\nObject: " << house.m_birdObj
        << "\nPointer: " << *house.m_birdPtr
        << "\nReference: " << house.m_birdRef;

    return out;
}