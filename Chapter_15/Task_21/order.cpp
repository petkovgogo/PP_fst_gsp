#include <fstream>

std::ofstream out("order.out.txt");

#define CLASS(ID)                                \
    class ID                                     \
    {                                            \
    public:                                      \
        ID(int) { out << #ID " constructor\n"; } \
        ~ID() { out << #ID " destructor\n"; }    \
    };

class Base1
{
public:
    Base1(int) { out << "\nBase1 constructor\n"; }
    virtual ~Base1() { out << "Base1 virtual destructor\n\n"; }

    virtual void func() { out << __PRETTY_FUNCTION__ << "\n"; }
};

CLASS(Member1);
CLASS(Member2);
CLASS(Member3);
CLASS(Member4);

class Derived1 : public Base1
{
private:
    Member1 m1;
    Member2 m2;

public:
    Derived1(int) : Base1(3), m1(2), m2(1)
    {
        out << "Derived1 constructor\n";
    }

    ~Derived1()
    {
        out << "Derived1 virtual destructor\n";
    }

    void func() { out << __PRETTY_FUNCTION__ << "\n\n"; }
};

class Derived2 : public Derived1
{
private:
    Member3 m3;
    Member4 m4;

public:
    Derived2() : Derived1(2), m3(1), m4(3)
    {
        out << "Derived2 constructor\n\n";
    }

    ~Derived2()
    {
        out << "Derived2 virtual destructor\n";
    }
    
    void func() { out << __PRETTY_FUNCTION__ << "\n\n"; }
};

int main()
{
    Derived1 d1(7);
    Derived2 d2;

    Base1 &baseRef1 = d1;
    Base1 &baseRef2 = d2;

    baseRef1.func();
    baseRef2.func();

    return 0;
}