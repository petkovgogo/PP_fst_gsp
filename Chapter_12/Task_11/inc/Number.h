#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>

class Number
{
private:
    double m_num;
public:
    Number(double num);

    Number &operator=(const Number &number);
    operator int() const;

    friend const Number operator+(const Number &num1, const Number &num2);
    friend const Number operator-(const Number &num1, const Number &num2);
    friend const Number operator*(const Number &num1, const Number &num2);
    friend const Number operator/(const Number &num1, const Number &num2);

    friend std::ostream &operator<<(std::ostream &out, const Number &num);
};

#endif // NUMBER_H