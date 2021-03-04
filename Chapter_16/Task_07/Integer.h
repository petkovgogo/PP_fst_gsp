#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>
#include <cstring>
#include <cmath>
#include "AutoCounter.h"

enum Sign
{
    Minus = -1,
    Plus = 1
};

class Integer
{
private:
    static int id;
    const int m_id;
    char *const m_name;
    AutoCounter m_ac;
    unsigned int m_num;
    Sign m_sign;

    char *identify()
    {
        const int BUF_SIZE = 20;
        char *str = new char[BUF_SIZE];

        strcpy(str, "Integer #");
        strcat(str, std::to_string(m_id).c_str());

        return str;
    }

    char *identify(const char *name)
    {
        const int BUF_SIZE = 20;
        char *str = new char[BUF_SIZE];

        strcpy(str, name);
        strcat(str, " copy");

        return str;
    }

public:
    Integer(unsigned int num, Sign sign = Plus) : m_id(++id), m_name(identify()), m_ac(m_name), m_num(num), m_sign(sign) {}
    Integer(const Integer &origin) : m_id(++id), m_name(identify(origin.m_name)),
                                     m_ac(m_name),
                                     m_num(origin.m_num),
                                     m_sign(origin.m_sign) {}

    ~Integer() { delete[] m_name; }

    friend const Integer operator+(const Integer &num1, const Integer &num2)
    {
        long result = static_cast<long>(num1.m_num) * num1.m_sign + static_cast<long>(num2.m_num) * num2.m_sign;
        Sign resultSign;

        if (num1.m_sign == num2.m_sign)
        {
            resultSign = num1.m_sign;
        }
        else
        {
            resultSign = num1.m_num > num2.m_num ? num1.m_sign : num2.m_sign;
        }

        return Integer(static_cast<unsigned int>(abs(result)), resultSign);
    }

    friend std::ostream &operator<<(std::ostream &out, const Integer &integer)
    {
        return out << static_cast<long>(integer.m_num) * integer.m_sign;
    }
};

int Integer::id;

#endif // INTEGER_H