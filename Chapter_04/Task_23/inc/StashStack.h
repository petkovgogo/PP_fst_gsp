#ifndef STASH_STACK_H
#define STASH_STACK_H

#include <fstream>
#include "Stack.h"
#include "Stash.h"

struct StashStack
{
    StashStack();
    void push(Stash *element);
    void push(std::ifstream &file);
    Stash *pop();
    void cleanup();

private:
    Stack m_stack;
};

#endif // STASH_STACK_H