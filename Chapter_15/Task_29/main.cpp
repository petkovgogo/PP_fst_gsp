class X
{
public:
    X() { func(); }

    // The local version is used, because the constructor of X
    // is called before the constructor of Y, which means Y is not yet 
    // initialised and calling its func() will result in undefined behaviour
    virtual void func() {}
};

class Y : public X
{
public:
    Y() { func(); }

    void func() {}
};

int main()
{
    // The virtual mechanism is not used - the compiler performs early binding
    Y yObj;

    return 0;
}