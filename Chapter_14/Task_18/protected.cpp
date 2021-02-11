#include <iostream>

class Base
{
private:
    int i;

protected:
    int read() const { return i; }
    void set(int ii) { i = ii; }

public:
    Base(int ii = 0) : i(ii) {}

    int value(int m) const { return m * i; }
};

class Derived : public Base
{
private:
    int j;

public:
    Derived(int jj = 0) : j(jj) {}

    void change(int x) { Base::set(x); }
    int read() const { return j; }
    int baseRead() const { return Base::read(); }
};

#define PRINT(EXP) \
    std::cout << #EXP " -> " << EXP << std::endl;

int main()
{
    Derived d(42);

    PRINT(d.read())
    PRINT(d.baseRead())

    d.change(451);

    PRINT(d.read())
    PRINT(d.baseRead())

    return 0;
}