#ifndef DOG_HOUSE_H
#define DOG_HOUSE_H

#include <iostream>
#include <string>
#include "Dog.h"

class DogHouse
{
    static int instances;
    const int m_id;
    Dog *m_dogPtr;
    std::string m_houseName;

public:
    DogHouse(Dog *dog, const std::string &house);
    DogHouse(const DogHouse &dh);
    DogHouse &operator=(const DogHouse &dh);
    // Decrement refcount, conditionally destroy
    ~DogHouse();

    void renameHouse(const std::string &newName);
    void unalias();

    // Copy-on-write. Anytime you modify the
    // contents of the pointer you must
    // first unalias it:
    void renameDog(const std::string &newName);
    // ... or when you allow someone else access:
    Dog *getDog();

    friend std::ostream &operator<<(std::ostream &os, const DogHouse &dh);
};

#endif // DOG_HOUSE_H