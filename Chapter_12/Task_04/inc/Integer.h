#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>

class Integer
{
private:
    int m_num;

public:
    Integer(int num = 0);

    const Integer operator+(const Integer &op) const;
    const Integer operator-(const Integer &op) const;
    const Integer &operator++();
    const Integer operator++(int);
    const Integer &operator--();
    const Integer operator--(int);
    
    void print(std::ostream &out) const;
};

#endif // INTEGER_H