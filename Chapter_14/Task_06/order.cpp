#include <fstream>

std::ofstream trace("order.out.txt");

#define CLASS(ID)                                  \
    class ID                                       \
    {                                              \
    public:                                        \
        ID(int) { trace << #ID " constructor\n"; } \
        ~ID() { trace << #ID " destructor\n"; }    \
    };

CLASS(Base1)
CLASS(Member1)
CLASS(Member2)
CLASS(Member3)
CLASS(Member4)
CLASS(Member5)

class Derived1 : public Base1
{
private:
    Member1 m1;
    Member2 m2;

public:
    Derived1(int) : Base1(3), m1(1), m2(2) { trace << "Derived1 constructor\n"; }
    ~Derived1() { trace << "Derived1 destructor\n"; }
};

class Derived2 : public Derived1
{
private:
    Member3 m3;
    Member4 m4;

public:
    Derived2(int) : Derived1(2), m3(1), m4(3) { trace << "Derived2 constructor\n"; }
    ~Derived2() { trace << "Derived2 destructor\n"; }
};

class Derived3 : public Derived2
{
private:
    Member4 m4;
    Member5 m5;

public:
    Derived3() : Derived2(2), m4(1), m5(3) { trace << "Derived3 constructor\n"; }
    ~Derived3() { trace << "Derived3 destructor\n"; }
};

int main()
{
    Derived3 d3;

    return 0;
}