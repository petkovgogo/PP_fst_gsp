#ifndef OSTACK_H
#define OSTACK_H

class Object
{
public:
    virtual ~Object() = 0;
};

// Required definition:
inline Object::~Object() {}

template <class T>
class Stack
{
private:
    struct Link
    {
        Object *data;
        Link *next;
        Link(Object *dat, Link *nxt) : data(dat), next(nxt) {}
    } * head;

public:
    Stack() : head(0) {}
    ~Stack()
    {
        while (head)
        {
            delete pop();
        }
    }

    void push(T *dat)
    {
        head = new Link(static_cast<Object *>(dat), head);
    }

    T *peek() const
    {
        return head ? static_cast<T *>(head->data) : 0;
    }

    T *pop()
    {
        if (head == 0)
        {
            return 0;
        }

        T *result = static_cast<T *>(head->data);
        Link *oldHead = head;
        head = head->next;

        delete oldHead;
        return result;
    }
};

#endif // OSTACK_H