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

class Derived : protected Base
{
private:
    int j;

public:
    Derived(int jj = 0) : j(jj) {}

    void change(int x) { set(x); }
};

int main()
{
    Derived d;
    d.change(10);

    // error: ‘Base’ is not an accessible base of ‘Derived’
    // d.value(7); // error: ‘int Base::value(int) const’ is inaccessible within this context
}