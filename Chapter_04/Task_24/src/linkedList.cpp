#include <iostream>
#include "../inc/LinkedList.h"

void LinkedListFunc::createList(LinkedList &linkedList, int size)
{
    LinkedList *p_list = &linkedList;
    for (int i = 0; i < size - 1; i++)
    {
        p_list->index = i;
        p_list->next = new LinkedList;
        p_list = p_list->next;
    }

    p_list->index = size - 1;
    p_list->next = 0;
}

void LinkedListFunc::printList(LinkedList &linkedList)
{
    LinkedList *p_list = &linkedList;
    while (p_list != 0)
    {
        std::cout << "Index: " << p_list->index << " (" << (long)p_list << ") -> Next: " <<
            (long)p_list->next << std::endl;
        p_list = p_list->next;
    }
}

void LinkedListFunc::cleanup(LinkedList &linkedList)
{
    LinkedList *p_list = linkedList.next;
    LinkedList *p_next;
    while (p_list != 0)
    {   
        p_next = p_list->next;
        delete p_list;
        p_list = p_next;
    }
}