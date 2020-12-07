#ifndef LIST_FUNC_H
#define LIST_FUNC_H

#include "LinkedList.h"

struct ListFunc
{
    static void createList(LinkedList &linkedList, int size);
    static void printList(LinkedList &linkedList);
    static void cleanup(LinkedList &linkedList);
};

#endif // LIST_FUNC_H