#ifndef TSTACK2_H
#define TSTACK2_H

#include <iostream>

template <class T>
class Stack
{
private:
    struct Link
    {
        T *data;
        Link *next;
        bool owns;

        Link(T *dat, Link *nxt, bool owned)
            : data(dat), next(nxt), owns(owned) {}
    } * head;

public:
    Stack() : head(0) {}
    ~Stack();

    void push(T *dat, bool owned = true)
    {
        head = new Link(dat, head, owned);
    }

    T *peek() const
    {
        return head ? head->data : 0;
    }

    T *pop();

    // Nested iterator class:
    class iterator;        // Declaration required
    friend class iterator; // Make it a friend
    class iterator
    {
    private:
        // Now define it
        Stack::Link *p;

    public:
        iterator(const Stack<T> &tl) : p(tl.head) {}

        // Copy-constructor:
        iterator(const iterator &tl) : p(tl.p) {}

        // The end sentinel iterator:
        iterator() : p(0) {}

        // operator++ returns boolean indicating end:
        bool operator++()
        {
            if (p->next)
            {
                p = p->next;
            }
            else
            {
                p = 0; // Indicates end of list
            }

            return bool(p);
        }

        bool operator++(int) { return operator++(); }

        T *current() const
        {
            if (!p)
            {
                return 0;
            }

            return p->data;
        }

        // Pointer dereference operator:
        T *operator->() const { return current(); }
        T *operator*() const { return current(); }

        // bool conversion for conditional test:
        operator bool() const { return bool(p); }

        // Comparison to test for end:
        bool operator==(const iterator &) const
        {
            return p == 0;
        }

        bool operator!=(const iterator &) const
        {
            return p != 0;
        }

        void changeOwnership(bool owner)
        {
            p->owns = owner;
        }

        bool owner() { return p->owns; }
    };

    iterator begin() const { return iterator(*this); }
    iterator end() const { return iterator(); }
};

template <class T>
Stack<T>::~Stack()
{
    while (head)
    {
        if (head->owns)
        {
            delete pop();
            continue;
        }

        pop();
    }
}

template <class T>
T *Stack<T>::pop()
{
    if (!head)
    {
        return 0;
    }

    T *result = head->data;
    Link *oldHead = head;
    head = head->next;

    delete oldHead;
    return result;
}

#endif // TSTACK2_H