#include <iostream>

// #define FIX_ALIAS

class Simple
{
private:
    int *m_numPtr;

public:
    Simple(int *pNum = 0) : m_numPtr(pNum) {}
    ~Simple() { delete m_numPtr; }

#ifdef FIX_ALIAS

    Simple &operator=(const Simple &simpleObj)
    {
        if (&simpleObj != this)
        {
            m_numPtr = new int(*simpleObj.m_numPtr);
        }

        return *this;
    }

#endif // FIX_ALIAS

    friend std::ostream &operator<<(std::ostream &out, const Simple &simpleObj);
};

std::ostream &operator<<(std::ostream &out, const Simple &simpleObj)
{
    out << (long)simpleObj.m_numPtr;

    return out;
}

int main()
{
    Simple simp1(new int(42));
    Simple simp2;

    simp2 = simp1;

    std::cout << "The addresses of both numbers:"
              << "\nsimp1: " << simp1
              << "\nsimp2: " << simp2 << std::endl;

    return 0;
}