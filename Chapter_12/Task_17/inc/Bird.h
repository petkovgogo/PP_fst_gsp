#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <string>

class Bird
{
private:
    std::string m_id;
    int m_num;

public:
    Bird(int num = 0);
    Bird(const Bird &origin);

    Bird &operator=(Bird &origin);
    friend const Bird operator+(const Bird &loperand, const Bird &roperand);
    friend const Bird operator-(const Bird &loperand, const Bird &roperand);
    friend const Bird operator*(const Bird &loperand, const Bird &roperand);
    friend const Bird operator/(const Bird &loperand, const Bird &roperand);

    friend std::ostream &operator<<(std::ostream &out, const Bird &bird);
};

#endif // BIRD_H