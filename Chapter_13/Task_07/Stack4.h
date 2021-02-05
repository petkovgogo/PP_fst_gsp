#ifndef STACK4_H
#define STACK4_H

#include <cassert>

class Stack
{
    struct Link
    {
        void *data;
        Link *next;
        Link(void *dat, Link *nxt);

    } * head;

public:
    Stack();
    ~Stack();

    void push(void *dat);
    void *peek() const;
    void *pop();
};

inline Stack::Stack() : head(0) {}

inline Stack::~Stack() { assert(head == 0); }

inline Stack::Link::Link(void *dat, Link *nxt) : data(dat), next(nxt) {}

inline void Stack::push(void *dat) { head = new Link(dat, head); }

inline void *Stack::peek() const { return head ? head->data : 0; }

inline void *Stack::pop()
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

#endif // STACK4_H