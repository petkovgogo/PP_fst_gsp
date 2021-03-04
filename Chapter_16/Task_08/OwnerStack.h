#ifndef OWNERSTACK_H
#define OWNERSTACK_H

#include <vector>

template <class T>
class Stack
{
private:
    std::vector<T> m_head;
    bool m_owner;

public:
    Stack(bool owner = true) : m_head(0), m_owner(owner) {}
    ~Stack();

    void push(const T &dat) { m_head.push_back(dat); }
    T &peek() const { return m_head.empty() ? 0 : m_head[m_head.size() - 1]; }
    T pop();

    bool owns() const { return m_owner; }
    void owns(bool newOwnership) { m_owner = newOwnership; }

    // Auto-type conversion: true if not empty:
    operator bool() const { return !m_head.empty(); }
};

template <class T>
T Stack<T>::pop()
{
    if (m_head.empty())
    {
        return 0;
    }

    T &result = m_head[m_head.size() - 1];
    m_head.pop_back();

    return result;
}

template <class T>
Stack<T>::~Stack()
{
    if (!m_owner)
    {
        return;
    }

    while (!m_head.empty())
    {
        delete pop();
    }
}

#endif // OWNERSTACK_H