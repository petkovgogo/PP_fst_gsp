#include "../inc/Stack2.h"

Stack::Link::Link(void *dat, Link *nxt)
{
    data = dat;
    next = nxt;
}

Stack::Link::~Link() {}

Stack::Stack() { head = 0; }

Stack::Stack(void *dataArr[], int arrSize)
{
    head = 0;

    for (int i = 0; i < arrSize; i++)
    {
        this->push(dataArr[i]);
    }
}

void Stack::push(void *dat)
{
    head = new Link(dat, head);
}

void *Stack::peek()
{
    return head->data;
}

void *Stack::pop()
{
    if (head == 0)
    {
        return 0;
    }

    void *result = head->data;
    Link *oldHead = head;
    head = head->next;

    delete oldHead;

    return result;
}

Stack::~Stack() {}