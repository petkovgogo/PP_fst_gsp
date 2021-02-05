#ifndef PSTASH_H
#define PSTASH_H

class PStash
{
    // Pointer storage:
    void **m_storage;

    int m_quantity; // Number of storage spaces
    int m_next;     // Next empty space

    void inflate(int increase);

public:
    PStash();
    ~PStash();

    int add(void *element);
    void *operator[](int index) const; // Fetch

    // Remove the reference from this PStash:
    void *remove(int index);

    // Number of elements in Stash:
    int count() const;
};

#endif // PSTASH_H