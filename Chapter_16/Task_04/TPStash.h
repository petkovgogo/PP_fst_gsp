#ifndef TPSTASH_H
#define TPSTASH_H

#include <iostream>
#include <cstring>
#include <cassert>

template <class T, int incr = 10>
class PStash
{
    int quantity;  // Number of storage spaces
    int next;      // Next empty space
    int incrValue; // Assigning the incr constant's value to a variable, so it can be changed later

    T **storage;

    void inflate(int increase = incr);

public:
    PStash() : quantity(0), next(0), incrValue(incr), storage(0) {}
    ~PStash();

    int add(T *element);

    int changeIncrValue(int newValue);

    T *operator[](int index) const; // Fetch

    // Remove the reference from this PStash:
    T *remove(int index);

    // Number of elements in Stash:
    int count() const { return next; }
};

// Ownership of remaining pointers:
template <class T, int incr>
PStash<T, incr>::~PStash()
{
    for (int i = 0; i < next; i++)
    {
        delete storage[i]; // Null pointers OK
        storage[i] = 0;    // Just to be safe
    }

    delete[] storage;
}

template <class T, int incr>
int PStash<T, incr>::add(T *element)
{
    if (next >= quantity)
    {
        inflate(incrValue);
    }

    storage[next++] = element;

    return (next - 1); // Index number
}

template <class T, int incr>
int PStash<T, incr>::changeIncrValue(int newValue)
{
    return incrValue = newValue;
}

template <class T, int incr>
T *PStash<T, incr>::operator[](int index) const
{
    assert(index >= 0);

    if (index >= next)
    {
        return 0; // To indicate the end
    }

    assert(storage[index] != 0);

    // Produce pointer to desired element:
    return storage[index];
}

template <class T, int incr>
T *PStash<T, incr>::remove(int index)
{
    // operator[] performs validity checks:
    T *v = operator[](index);

    // "Remove" the pointer:
    if (v)
    {
        storage[index] = 0;
    }

    return v;
}

template <class T, int incr>
void PStash<T, incr>::inflate(int increase)
{
    std::cout
        << __PRETTY_FUNCTION__
        << " used. Current increnent value:"
        << increase
        << " New increment value: "
        << (incrValue *= 2)
        << std::endl;

    const int psz = sizeof(T *);
    T **st = new T *[quantity + increase];

    memset(st, 0, (quantity + increase) * psz);
    memcpy(st, storage, quantity * psz);

    quantity += increase;
    delete[] storage; // Old storage
    storage = st;     // Point to new memory
}

#endif // TPSTASH_H