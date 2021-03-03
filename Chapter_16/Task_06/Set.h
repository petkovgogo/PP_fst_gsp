#ifndef SET_H
#define SET_H

#include <cassert>
#include <vector>

template <class T>
class Set
{
private:
    std::vector<T> m_storage;

    bool compare(const T &val1, const T &val2) { return val1 == val2; }

public:
    class iterator;
    friend class iterator;
    class iterator
    {
    private:
        Set &m_set;
        size_t m_index;

    public:
        iterator(Set &set) : m_set(set), m_index(0) {}
        iterator(Set &set, bool) : m_set(set), m_index(set.size()) {}
        iterator(const iterator &origin) : m_set(origin.m_set), m_index(origin.m_index) {}

        iterator &operator=(const iterator &rvalue)
        {
            if (this != &rvalue)
            {
                this->m_set = rvalue.m_set;
                this->m_index = rvalue.m_index;
            }

            return *this;
        }

        iterator &operator++()
        {
            assert(++m_index <= m_set.size());

            return *this;
        }

        const iterator operator++(int)
        {
            iterator temp(*this);

            assert(++m_index <= m_set.size());

            return temp;
        }

        iterator &operator--()
        {
            assert(--m_index >= 0);

            return *this;
        }

        const iterator operator--(int)
        {
            iterator temp(*this);

            assert(--m_index >= 0);

            return temp;
        }

        iterator &operator+=(int amount)
        {
            assert((m_index += amount) <= m_set.size());

            return *this;
        }

        iterator &operator-=(int amount)
        {
            assert((m_index -= amount) >= 0);

            return *this;
        }

        friend iterator operator+(const iterator &it, const int amount)
        {
            iterator temp(it);

            temp += amount;

            return temp;
        }

        T &operator*() const { return m_set.m_storage[m_index]; }
        T &operator->() const { return m_set.m_storage[m_index]; }

        bool operator==(const iterator &it) const
        {
            return m_index == it.m_index;
        }

        bool operator!=(const iterator &it) const
        {
            return m_index != it.m_index;
        }
    };

    int insert(const T &elem)
    {
        for (auto i = m_storage.begin(); i < m_storage.end(); i++)
        {
            if (compare(*i, elem))
            {
                return m_storage.size() - 1;
            }
        }

        m_storage.push_back(elem);

        return m_storage.size() - 1;
    }

    T &erase(const iterator &pos)
    {
        T *elem;

        for (size_t i = 0; i < m_storage.size(); i++)
        {
            if (&(*pos) == &m_storage[i])
            {
                elem = &m_storage[i];
                m_storage.erase(m_storage.begin() + i);
                break;
            }
        }

        return *elem;
    }

    void erase(iterator start, iterator end)
    {
        while (end != start)
        {
            erase(--end);
        }
    }

    size_t size() { return m_storage.size(); }

    iterator begin() { return iterator(*this); }
    iterator end() { return iterator(*this, true); }
};

#endif // SET_H