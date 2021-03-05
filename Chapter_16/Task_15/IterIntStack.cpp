#include <iostream>

class IntStack
{
private:
    static const int ssize = 100;

    int stack[ssize];
    int top;

public:
    IntStack() : top(0) {}

    void push(int i)
    {
        stack[top++] = i;
    }

    int pop()
    {
        return stack[--top];
    }

    class IntStackIter;
    friend class IntStackIter;
    // An iterator is like a "smart" pointer:
    class IntStackIter
    {
        IntStack &s;
        int index;

    public:
        IntStackIter(IntStack &is) : s(is), index(0) {}
        IntStackIter(IntStack &is, bool) : s(is), index(is.top) {}

        int operator++()
        { // Prefix
            return s.stack[++index];
        }

        int operator++(int)
        { // Postfix
            return s.stack[index++];
        }

        friend bool operator==(const IntStackIter &it1, const IntStackIter &it2)
        {
            return it1.index == it2.index;
        }

        friend bool operator!=(const IntStackIter &it1, const IntStackIter &it2)
        {
            return it1.index != it2.index;
        }
    };

    IntStackIter begin() { return IntStackIter(*this); }
    IntStackIter end() { return IntStackIter(*this, true); }
};

int fibonacci(int n)
{
    const int sz = 100;

    static int f[sz]; // Initialized to zero
    f[0] = f[1] = 1;

    // Scan for unfilled array elements:
    int i;

    for (i = 0; i < sz; i++)
    {
        if (f[i] == 0)
        {
            break;
        }
    }

    while (i <= n)
    {
        f[i] = f[i - 1] + f[i - 2];
        i++;
    }

    return f[n];
}

int main()
{
    IntStack is;

    for (int i = 0; i < 20; i++)
    {
        is.push(fibonacci(i));
    }

    // Traverse with an iterator:
    IntStack::IntStackIter it = is.begin();

    while (it != is.end())
    {
        std::cout << it++ << std::endl;
    }

    return 0;
}