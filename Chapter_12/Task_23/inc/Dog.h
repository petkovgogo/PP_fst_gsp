#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>

class Dog
{
private:
    static int instances;
    const int m_id;

    std::string m_name;
    int m_refcount;

    Dog(const std::string &name);

    // Prevent assignment:
    Dog &operator=(const Dog &);

public:
    Dog(const Dog &d);
    ~Dog();

    // Dogs can only be created on the heap:
    static Dog *make(const std::string &name);
    void attach();
    void detach();

    // Conditionally copy this Dog.
    // Call before modifying the Dog, assign
    // resulting pointer to your Dog*.
    Dog *unalias();
    void rename(const std::string &newName);
    friend std::ostream &operator<<(std::ostream &os, const Dog &d);
};

#endif // DOG_H