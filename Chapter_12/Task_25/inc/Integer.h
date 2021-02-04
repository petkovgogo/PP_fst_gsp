#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>

// Non-member functions:
class Integer
{
    long m_int;
    Integer *instance() { return this; }

public:
    Integer(long num = 0);

    // No side effects takes const& argument:
    friend const Integer &operator+(const Integer &integer);
    friend const Integer operator-(const Integer &integer);
    friend const Integer operator~(const Integer &integer);
    friend Integer *operator&(Integer &integer);
    friend int operator!(const Integer &integer);

    // Side effects have non-const& argument:
    // Prefix:
    friend const Integer &operator++(Integer &integer);
    friend const Integer &operator--(Integer &integer);
    // Postfix:
    friend const Integer operator++(Integer &integer, int);
    friend const Integer operator--(Integer &integer, int);

    // Operators that create new, modified value:
    friend const Integer operator+(const Integer &loperand, const Integer &roperand);
    friend const Integer operator-(const Integer &loperand, const Integer &roperand);
    friend const Integer operator*(const Integer &loperand, const Integer &roperand);
    friend const Integer operator/(const Integer &loperand, const Integer &roperand);
    friend const Integer operator%(const Integer &loperand, const Integer &roperand);
    friend const Integer operator^(const Integer &loperand, const Integer &roperand);
    friend const Integer operator&(const Integer &loperand, const Integer &roperand);
    friend const Integer operator|(const Integer &loperand, const Integer &roperand);
    friend const Integer operator<<(const Integer &loperand, const Integer &roperand);
    friend const Integer operator>>(const Integer &loperand, const Integer &roperand);

    // Assignments modify & return lvalue:
    friend Integer &operator+=(Integer &loperand, const Integer &roperand);
    friend Integer &operator-=(Integer &loperand, const Integer &roperand);
    friend Integer &operator*=(Integer &loperand, const Integer &roperand);
    friend Integer &operator/=(Integer &loperand, const Integer &roperand);
    friend Integer &operator%=(Integer &loperand, const Integer &roperand);
    friend Integer &operator^=(Integer &loperand, const Integer &roperand);
    friend Integer &operator&=(Integer &loperand, const Integer &roperand);
    friend Integer &operator|=(Integer &loperand, const Integer &roperand);
    friend Integer &operator>>=(Integer &loperand, const Integer &roperand);
    friend Integer &operator<<=(Integer &loperand, const Integer &roperand);

    // Conditional operators return true/false:
    friend int operator==(const Integer &loperand, const Integer &roperand);
    friend int operator!=(const Integer &loperand, const Integer &roperand);
    friend int operator<(const Integer &loperand, const Integer &roperand);
    friend int operator>(const Integer &loperand, const Integer &roperand);
    friend int operator<=(const Integer &loperand, const Integer &roperand);
    friend int operator>=(const Integer &loperand, const Integer &roperand);
    friend int operator&&(const Integer &loperand, const Integer &roperand);
    friend int operator||(const Integer &loperand, const Integer &roperand);

    // Write the contents to an ostream:
    friend std::ostream &operator<<(std::ostream &out, const Integer &integer);
};

#endif // INTEGER_H