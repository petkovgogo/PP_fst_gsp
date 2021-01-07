#ifndef HOLDER_H
#define HOLDER_H

const int SIZE = 20;

class Holder
{
    int arr[SIZE];

public:
    Holder();
    struct Pointer;
    friend Pointer;

    class Pointer
    {
        Holder *h;
        int *p;

    public:
        Pointer(Holder *h);

        // Move around in the array:
        void next();
        void previous();
        void top();
        void end();

        // Access values:
        int read();
        void set(int i);
    };
};

inline void Holder::Pointer::next()
{
    if (p < &(h->arr[SIZE - 1]))
    {
        p++;
    }
}

inline void Holder::Pointer::previous()
{
    if (p > &(h->arr[0]))
    {
        p--;
    }
}

inline void Holder::Pointer::top()
{
    p = &(h->arr[0]);
}

inline void Holder::Pointer::end()
{
    p = &(h->arr[SIZE - 1]);
}

inline int Holder::Pointer::read()
{
    return *p;
}

inline void Holder::Pointer::set(int i)
{
    *p = i;
}

#endif // HOLDER_H