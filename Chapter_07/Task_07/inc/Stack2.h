#ifndef STACK2_H
#define STACK2_H

class Stack
{
    struct Link
    {
        void *data;
        Link *next;
        Link(void *dat, Link *nxt);
        ~Link();
    } * head;

public:
    Stack();
    Stack(void *dataArr[], int arrSize);
    ~Stack();

    void push(void *dat);
    void *peek();
    void *pop();
};

#endif // STACK2_H