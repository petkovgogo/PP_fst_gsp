#include <iostream>

class Integer
{
private:
    int m_num;

public:
    Integer(int num = 0);

    const Integer operator++(int secret);
    const Integer operator--(int secret);

    void print(std::ostream &out) const;
};

Integer::Integer(int num) : m_num(num) {}

const Integer Integer::operator++(int secret)
{
    std::cout << "Secret value for ++ is " << secret << std::endl;

    Integer temp(*this);
    m_num++;

    return temp;
}

const Integer Integer::operator--(int secret)
{
    std::cout << "Secret value for -- is " << secret << std::endl;

    Integer temp(*this);
    m_num--;

    return temp;
}

void Integer::print(std::ostream &out) const
{
    out << m_num << std::endl;
}

int main()
{
    Integer number(42);

    (number++).print(std::cout);
    (number--).print(std::cout);

    return 0;
}