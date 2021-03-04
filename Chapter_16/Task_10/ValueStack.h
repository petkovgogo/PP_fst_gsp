#ifndef VALUESTACK_H
#define VALUESTACK_H

#include <vector>

template <class T>
class Stack
{
private:
    std::vector<T> m_stack;

public:
    void push(const T &x)
    {
        m_stack.push_back(x);
    }

    T peek() const { return m_stack[m_stack.size() - 1]; }

    T pop()
    {
        T *result = &m_stack[m_stack.size() - 1];
        m_stack.pop_back();

        return *result;
    }
};

#endif // VALUESTACK_H