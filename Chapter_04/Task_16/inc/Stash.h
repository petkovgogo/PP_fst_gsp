#ifndef STASH_H
#define STASH_H

#include <vector>

struct Stash
{
    int size; // Size of each space
    int next; // Next empty space
    
    // vector of bytes
    std::vector<char> storage;

    void initialize(int size);
    void cleanup();
    int add(const void *element);
    void *fetch(int index);
    int count();
};

#endif // STASH_H