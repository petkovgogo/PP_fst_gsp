#include <iostream>

class Simple
{
private:
    int m_num;

public:
    Simple() : m_num(0) {}
    const Simple &operator++()
    {
        ++m_num;
        return *this;
    }

    void print() const { std::cout << m_num << std::endl; }
};

int main()
{
    Simple simpleObj;

    (++simpleObj).print();
    // (simpleObj++).print(); // error: no ‘operator++(int)’ declared for postfix ‘++’

    return 0;
}