#include <iostream>
#include <string>
#include <cassert>
#include "../inc/Dog.h"

int Dog::instances = 0;

Dog::Dog(const std::string &name) : m_id(++instances), m_name(name), m_refcount(1)
{
    std::cout << "Creating Dog: " << *this << std::endl;
}

Dog::Dog(const Dog &d) : m_id(++instances), m_name(d.m_name + " copy"), m_refcount(1)
{
    std::cout << "Dog copy-constructor: " << *this << std::endl;
}

Dog::~Dog()
{
    std::cout << "Deleting Dog: " << *this << std::endl;
}

Dog *Dog::make(const std::string &name)
{
    return new Dog(name);
}

void Dog::attach()
{
    ++m_refcount;
    std::cout << "Attached Dog: " << *this << std::endl;
}

void Dog::detach()
{
    assert(m_refcount != 0);

    std::cout << "Detaching Dog: " << *this << std::endl;

    // Destroy object if no one is using it:
    if (--m_refcount == 0)
    {
        delete this;
    }
}

Dog *Dog::unalias()
{
    std::cout << "Unaliasing Dog: " << *this << std::endl;

    // Don't duplicate if not aliased:
    if (m_refcount == 1)
    {
        return this;
    }

    --m_refcount;

    // Use copy-constructor to duplicate:
    return new Dog(*this);
}

void Dog::rename(const std::string &newName)
{
    m_name = newName;
    std::cout << "Dog renamed to: " << *this << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Dog &d)
{
    return os << "[" << d.m_name << "], "
              << "dog instance #" << d.m_id << ", rc = " << d.m_refcount;
}