#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct LinkedList
{
    int m_index;
    LinkedList *m_next;

    static void createList(LinkedList &linkedList, int size);
    static void printList(LinkedList &linkedList);
    static void cleanup(LinkedList &linkedList);
};

#endif // LINKED_LIST_H