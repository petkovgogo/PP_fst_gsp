#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct LinkedList
{
    int index;
    LinkedList *next;
};

void createList(LinkedList &linkedList, int size);
void printList(LinkedList &linkedList);
void cleanup(LinkedList &linkedList);

#endif // LINKED_LIST_H