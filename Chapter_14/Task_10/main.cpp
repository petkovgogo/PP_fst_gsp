#include <iostream>

class Simple
{
private:
    long m_num;

public:
    Simple(long num) : m_num(num) {}

    long getNum() const { return m_num; }
};

int main()
{
    long num = 4000000000000L;

    Simple simpleObj(num);
    std::cout << simpleObj.getNum() << std::endl;

    return 0;
}