#include <iostream>
#include <cassert>
#include "../inc/Integer.h"

Integer::Integer(long num) : m_int(num) {}

// Global operators:
const Integer &operator+(const Integer &integer)
{
    std::cout << "+Integer\n";

    return integer; // Unary + has no effect
}

const Integer operator-(const Integer &integer)
{
    std::cout << "-Integer\n";

    return Integer(-integer.m_int);
}

const Integer operator~(const Integer &integer)
{
    std::cout << "~Integer\n";

    return Integer(~integer.m_int);
}

Integer *operator&(Integer &integer)
{
    std::cout << "&Integer\n";

    return integer.instance(); // &integer is recursive!
}

int operator!(const Integer &integer)
{
    std::cout << "!Integer\n";

    return !integer.m_int;
}

// Prefix; return incremented value
const Integer &operator++(Integer &integer)
{
    std::cout << "++Integer\n";

    integer.m_int++;

    return integer;
}

// Postfix; return the value before increment:
const Integer operator++(Integer &integer, int)
{
    std::cout << "Integer++\n";

    Integer before(integer.m_int);
    integer.m_int++;

    return before;
}

// Prefix; return decremented value
const Integer &operator--(Integer &integer)
{
    std::cout << "--Integer\n";

    integer.m_int--;

    return integer;
}

// Postfix; return the value before decrement:
const Integer operator--(Integer &integer, int)
{
    std::cout << "Integer--\n";

    Integer before(integer.m_int);
    integer.m_int--;

    return before;
}

const Integer operator+(const Integer &loperand, const Integer &roperand) { return Integer(loperand.m_int + roperand.m_int); }
const Integer operator-(const Integer &loperand, const Integer &roperand) { return Integer(loperand.m_int - roperand.m_int); }
const Integer operator*(const Integer &loperand, const Integer &roperand) { return Integer(loperand.m_int * roperand.m_int); }

const Integer operator/(const Integer &loperand, const Integer &roperand)
{
    assert(roperand.m_int != 0);

    return Integer(loperand.m_int / roperand.m_int);
}

const Integer operator%(const Integer &loperand, const Integer &roperand)
{
    assert(roperand.m_int != 0);

    return Integer(loperand.m_int % roperand.m_int);
}

const Integer operator^(const Integer &loperand, const Integer &roperand) { return Integer(loperand.m_int ^ roperand.m_int); }
const Integer operator&(const Integer &loperand, const Integer &roperand) { return Integer(loperand.m_int & roperand.m_int); }
const Integer operator|(const Integer &loperand, const Integer &roperand) { return Integer(loperand.m_int | roperand.m_int); }
const Integer operator<<(const Integer &loperand, const Integer &roperand) { return Integer(loperand.m_int << roperand.m_int); }
const Integer operator>>(const Integer &loperand, const Integer &roperand) { return Integer(loperand.m_int >> roperand.m_int); } 

// Assignments modify & return lvalue:
Integer &operator+=(Integer &loperand, const Integer &roperand)
{
    if (&loperand == &roperand) { /* self-assignment */ }

    loperand.m_int += roperand.m_int;

    return loperand;
}

Integer &operator-=(Integer &loperand, const Integer &roperand)
{
    if (&loperand == &roperand) { /* self-assignment */ }

    loperand.m_int -= roperand.m_int;

    return loperand;
}

Integer &operator*=(Integer &loperand, const Integer &roperand)
{
    if (&loperand == &roperand) { /* self-assignment */ }

    loperand.m_int *= roperand.m_int;

    return loperand;
}

Integer &operator/=(Integer &loperand, const Integer &roperand)
{
    assert(roperand.m_int != 0);

    if (&loperand == &roperand) { /* self-assignment */ }

    loperand.m_int /= roperand.m_int;

    return loperand;
}

Integer &operator%=(Integer &loperand, const Integer &roperand)
{
    assert(roperand.m_int != 0);

    if (&loperand == &roperand) { /* self-assignment */ }

    loperand.m_int %= roperand.m_int;

    return loperand;
}

Integer &operator^=(Integer &loperand, const Integer &roperand)
{
    if (&loperand == &roperand) { /* self-assignment */ }

    loperand.m_int ^= roperand.m_int;

    return loperand;
}

Integer &operator&=(Integer &loperand, const Integer &roperand)
{
    if (&loperand == &roperand) { /* self-assignment */ }

    loperand.m_int &= roperand.m_int;

    return loperand;
}

Integer &operator|=(Integer &loperand, const Integer &roperand)
{
    if (&loperand == &roperand) { /* self-assignment */ }

    loperand.m_int |= roperand.m_int;

    return loperand;
}

Integer &operator>>=(Integer &loperand, const Integer &roperand)
{
    if (&loperand == &roperand) { /* self-assignment */ }

    loperand.m_int >>= roperand.m_int;

    return loperand;
}

Integer &operator<<=(Integer &loperand, const Integer &roperand)
{
    if (&loperand == &roperand) { /* self-assignment */ }

    loperand.m_int <<= roperand.m_int;

    return loperand;
}

// Conditional operators return true/false:
int operator==(const Integer &loperand, const Integer &roperand) { return loperand.m_int == roperand.m_int; }
int operator!=(const Integer &loperand, const Integer &roperand) { return loperand.m_int != roperand.m_int; }
int operator<(const Integer &loperand, const Integer &roperand)  { return loperand.m_int <  roperand.m_int; }
int operator>(const Integer &loperand, const Integer &roperand)  { return loperand.m_int >  roperand.m_int; }
int operator<=(const Integer &loperand, const Integer &roperand) { return loperand.m_int <= roperand.m_int; }
int operator>=(const Integer &loperand, const Integer &roperand) { return loperand.m_int >= roperand.m_int; }
int operator&&(const Integer &loperand, const Integer &roperand) { return loperand.m_int && roperand.m_int; }
int operator||(const Integer &loperand, const Integer &roperand) { return loperand.m_int || roperand.m_int; }

std::ostream &operator<<(std::ostream &out, const Integer &integer)
{
    return out << integer.m_int;
}