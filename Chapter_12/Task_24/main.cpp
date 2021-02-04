#include <iostream>

class Simple
{
private:
    const char *m_str;

public:
    Simple(const char *str) : m_str(str) {}

    friend std::ostream &operator<<(std::ostream &out, const Simple &simpleObj)
    {
        return out << simpleObj.m_str;
    }
};

class SimpleHolder
{
private:
    Simple m_simpleObj;

public:
    SimpleHolder(const Simple &simpleObj) : m_simpleObj(simpleObj) {}

    friend std::ostream &operator<<(std::ostream &out, const SimpleHolder &sh)
    {
        return out << sh.m_simpleObj;
    }
};

#define PRINT(EXP) \
    std::cout << #EXP " -> " << EXP << std::endl;

int main()
{
    Simple simpleObj1("Lorem ipsum dolor sit amet");
    Simple simpleObj2(simpleObj1);
    Simple simpleObj3 = "dummy text";

    PRINT(simpleObj1)
    PRINT(simpleObj2)
    PRINT(simpleObj3)
    PRINT((simpleObj1 = simpleObj3))    // synthesized op=

    SimpleHolder sh1(simpleObj2);
    SimpleHolder sh2(Simple("dummy text"));
    SimpleHolder sh3 = sh2;             // copy-construction

    PRINT(sh1)
    PRINT(sh2)
    PRINT(sh3)
    PRINT((sh3 = sh1))                  // synthesized op=

    return 0;
}