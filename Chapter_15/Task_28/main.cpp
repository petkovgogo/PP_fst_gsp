class X
{
public:
    virtual void func() {}
};

class Y : public X
{
public:
    void func() {}
};

int main()
{
    // Both default constructors are synthesized and called by the compiler
    Y yObj;

    return 0;
}