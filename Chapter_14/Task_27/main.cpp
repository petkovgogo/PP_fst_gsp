#include <iostream>

class Subject
{
public:
    // I'm using virtual functions to easily show which function is used from which implementation.
    // The functions are pure virtual to force their overriding, so that there is a difference between implementations 
    virtual void f() const = 0;
    virtual void g() const = 0;
    virtual void h() const = 0;
    virtual const char *identify() const = 0;
};

class Proxy : public Subject
{
private:
    Subject *m_subject;

public:
    Proxy(Subject *subject) : m_subject(subject) {}

    void f() const { m_subject->f(); }
    void g() const { m_subject->g(); }
    void h() const { m_subject->h(); }

    const char *identify() const { return "Proxy"; }

    void changeImp(Subject *subject)
    {
        m_subject = subject;
        std::cout << "Changed implementation to " << m_subject->identify() << std::endl;
    }
};

class Implementation1 : public Subject
{
    void f() const { std::cout << __PRETTY_FUNCTION__ << "\n"; }
    void g() const { std::cout << __PRETTY_FUNCTION__ << "\n"; }
    void h() const { std::cout << __PRETTY_FUNCTION__ << "\n"; }

    const char *identify() const { return "Implementation 1"; }
};

class Implementation2 : public Subject
{
    void f() const { std::cout << __PRETTY_FUNCTION__ << "\n"; }
    void g() const { std::cout << __PRETTY_FUNCTION__ << "\n"; }
    void h() const { std::cout << __PRETTY_FUNCTION__ << "\n"; }

    const char *identify() const { return "Implementation 2"; }
};

#define CALL(EXP)            \
    std::cout << #EXP " -> "; \
    EXP;

void callAllFunctions(Proxy &proxy)
{
    std::cout << std::endl; // empty line for console formatting

    CALL(proxy.f())
    CALL(proxy.g())
    CALL(proxy.h())

    std::cout << std::endl; // empty line for console formatting
}

int main()
{
    Implementation1 imp1;
    Implementation2 imp2;

    Proxy proxy1(&imp1);
    Proxy proxy2(&imp2);

    CALL(callAllFunctions(proxy1));
    CALL(callAllFunctions(proxy2));

    CALL(proxy1.changeImp(&imp2))
    CALL(proxy2.changeImp(&imp1))
    std::cout << std::endl; // empty line for console formatting

    CALL(callAllFunctions(proxy1));
    CALL(callAllFunctions(proxy2));

    return 0;
}