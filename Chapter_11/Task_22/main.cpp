class X
{
private:
    int m_num;
    X(X &xObj);

public:
    X() : m_num(0) {}

    void increment() { m_num++; }
    X *clone() const
    {
        X *xPtr = new X();
        xPtr->m_num = this->m_num;

        return xPtr;
    }
};

void modify(const X &xObj)
{
    X *copy = xObj.clone();

    // xObj.increment();    // error: passing ‘const X’ as ‘this’ argument discards qualifiers
    copy->increment();      // fine this is a copy

    delete copy;
}

int main()
{
    X xObj;

    modify(xObj);

    return 0;
}