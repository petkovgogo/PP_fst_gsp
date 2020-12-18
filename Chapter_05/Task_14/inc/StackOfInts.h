#ifndef STACK_OF_INTS_H
#define STACK_OF_INTS_H

class StackImp;

const int STACK_CAPACITY = 42;

class StackOfInts
{
private:
    StackImp *m_stack;
public:
    StackOfInts();
    ~StackOfInts();

    void push(int value);
    int peek();
    int pop();
    void cleanup();
};

#endif // STACK_OF_INTS_H