#include <iostream>
#include "../inc/Stack.h"

void Stack::Link::initialize(void *dat, Link *nxt)
{
    data = dat;
    next = nxt;
}

void Stack::initialize() { head = 0; }

void Stack::push(void *dat)
{
    Link *newLink = new Link;
    newLink->initialize(dat, head);
    head = newLink;
}

void *Stack::peek()
{
    return head->data;
}

void *Stack::pop()
{
    if (head == 0) // when there is no next element
    {
        return 0;
    }

    void *result = head->data;
    Link *oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
}

void Stack::cleanup()
{
    if (head != 0) // if head is not zero, it means there are still elements in the stack
    {
        std::cout << "Stack is not empty" << std::endl;
    }
}