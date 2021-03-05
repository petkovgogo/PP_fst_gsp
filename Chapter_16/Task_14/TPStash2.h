#ifndef TPSTASH2_H
#define TPSTASH2_H

#include <vector>

template <class T>
class PStash
{
private:
    std::vector<T *> m_storage;

public:
    PStash();
    ~PStash();

    int add(T *element);
    T *operator[](size_t index) const;
    T *remove(int index);
    size_t count() const;

    // Nested iterator class:
    class iterator;        // Declaration required
    friend class iterator; // Make it a friend
    class iterator
    {
    private:
        PStash &ps;
        int m_index;

    public:
        iterator(PStash &pStash) : ps(pStash), m_index(0) {}

        // To create the end sentinel:
        iterator(PStash &pStash, bool) : ps(pStash), m_index(ps.m_storage.size()) {}

        // Copy-constructor:
        iterator(const iterator &rv) : ps(rv.ps), m_index(rv.m_index) {}

        iterator &operator=(const iterator &rv)
        {
            ps = rv.ps;
            m_index = rv.m_index;

            return *this;
        }

        iterator &operator++()
        {
            ++m_index;

            return *this;
        }

        iterator &operator++(int) { return operator++(); }

        iterator &operator--()
        {
            --m_index;

            return *this;
        }

        iterator &operator--(int) { return operator--(); }

        // Jump interator forward or backward:
        iterator &operator+=(int amount)
        {
            m_index += amount;

            return *this;
        }

        iterator &operator-=(int amount)
        {
            m_index -= amount;

            return *this;
        }

        // Create a new iterator that's moved forward
        iterator operator+(int amount) const
        {
            iterator ret(*this);
            ret += amount; // op+= does bounds check

            return ret;
        }

        T *current() const { return ps.m_storage[m_index]; }
        T *operator*() const { return current(); }
        T *operator->() const { return current(); }

        // Remove the current element:
        T *remove() { return ps.remove(m_index); }

        // Comparison tests for end:
        bool operator==(const iterator &rv) const { return m_index == rv.m_index; }
        bool operator!=(const iterator &rv) const { return m_index != rv.m_index; }
    };

    iterator begin() { return iterator(*this); }
    iterator end() { return iterator(*this, true); }
};

template <class T>
PStash<T>::PStash() {}

// Destruction of contained objects:
template <class T>
PStash<T>::~PStash()
{
    for (size_t i = 0; i < m_storage.size(); i++)
    {
        delete m_storage[i]; // Null pointers OK
        m_storage[i] = 0;    // Just to be safe
    }
}

template <class T>
int PStash<T>::add(T *element)
{
    m_storage.push_back(element);

    return (m_storage.size() - 1); // Index number
}

template <class T>
T *PStash<T>::operator[](size_t index) const
{
    if (index >= m_storage.size())
    {
        return 0; // To indicate the end
    }

    return m_storage[index];
}

template <class T>
T *PStash<T>::remove(int index)
{
    // operator[] performs validity checks:
    T *v = operator[](index);

    // "Remove" the pointer:
    m_storage[index] = 0;

    return v;
}

template <class T>
size_t PStash<T>::count() const { return m_storage.size(); }

#endif // TPSTASH2_H