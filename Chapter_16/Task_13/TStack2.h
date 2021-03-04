#ifndef TSTACK2_H
#define TSTACK2_H

#include <cassert>
#include <stack>

template <class T>
class Stack
{
private:
    std::stack<T *> m_storage;

public:
    ~Stack()
    {
        while (!m_storage.empty())
        {
            delete m_storage.top();
            m_storage.pop();
        }
    }

    class iterator;
    friend class iterator;
    class iterator
    {
    private:
        Stack &m_stack;
        size_t m_top;

    public:
        iterator(Stack &stack) : m_stack(stack), m_top(0) {}
        iterator(Stack &stack, bool) : m_stack(stack), m_top(stack.m_storage.size()) {}
        iterator(const iterator &origin) : m_stack(origin.m_stack), m_top(origin.m_top) {}

        iterator &operator=(const iterator &rvalue)
        {
            if (this != &rvalue)
            {
                this->m_stack = rvalue.m_stack;
                this->m_top = rvalue.m_top;
            }

            return *this;
        }

        bool operator++()
        {
            if (++m_top == m_stack.m_storage.size())
            {
                return false;
            }

            return true;
        }

        bool operator++(int)
        {
            return operator++();
        }

        bool operator--()
        {
            if (--m_top == 0)
            {
                return false;
            }

            return true;
        }

        const iterator operator--(int)
        {
            return operator--();
        }

        iterator &operator+=(int amount)
        {
            assert((m_top += amount) <= m_stack.size());

            return *this;
        }

        iterator &operator-=(int amount)
        {
            assert((m_top -= amount) >= 0);

            return *this;
        }

        friend iterator operator+(const iterator &it, const int amount)
        {
            iterator temp(it);

            temp += amount;

            return temp;
        }

        T *operator*() const
        {
            std::stack<T *> temp(m_stack.m_storage);

            while (temp.size() != m_top)
            {
                temp.pop();
            }

            return temp.top();
        }

        T *operator->() const
        {
            std::stack<T *> temp(m_stack.m_storage);

            while (temp.size() != m_top + 1)
            {
                temp.pop();
            }

            return temp.top();
        }

        bool operator==(const iterator &it) const
        {
            return m_top == it.m_top;
        }

        bool operator!=(const iterator &it) const
        {
            return m_top != it.m_top;
        }
    };

    void push(T *dat)
    {
        m_storage.push(dat);
    }

    T &peek() const
    {
        return m_storage.empty() ? 0 : m_storage.top();
    }

    T &pop()
    {
        T &result = m_storage.top();

        m_storage.pop();

        return result;
    }

    iterator begin() { return iterator(*this); }
    iterator end() { return iterator(*this, true); }
};

#endif // TSTACK2_H