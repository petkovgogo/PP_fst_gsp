#include "../inc/LinkedList.h"

#include <iostream>

void LinkedList::createList(LinkedList &linkedList, int size)
{
    LinkedList *p_list = &linkedList;

    for (int i = 0; i < size - 1; i++)
    {
        p_list->m_index = i;
        p_list->m_next = new LinkedList;
        p_list = p_list->m_next;
    }

    p_list->m_index = size - 1;
    p_list->m_next = 0;
}

void LinkedList::printList(LinkedList &linkedList)
{
    LinkedList *p_list = &linkedList;

    while (p_list != 0)
    {
        std::cout
            << "Index: "
            << p_list->m_index
            << " (" << (long)p_list << ") -> Next: "
            << (long)p_list->m_next
            << std::endl;

        p_list = p_list->m_next;
    }
}

void LinkedList::cleanup(LinkedList &linkedList)
{
    LinkedList *p_list = linkedList.m_next;
    LinkedList *p_next;

    while (p_list != 0)
    {
        p_next = p_list->m_next;
        delete p_list;
        p_list = p_next;
    }
}