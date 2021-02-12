#ifndef FRAMIS_H
#define FRAMIS_H

#include <fstream>

std::ofstream out("Framis.out.txt");

class Framis
{
private:
    static const int sz = 10;
    char c[sz]; // To take up space, not used
    static unsigned char pool[];
    static bool alloc_map[];

public:
    static const int psize = 100; // frami allowed

    Framis() { out << "Framis()\n"; }
    ~Framis() { out << "~Framis() ... "; }

    void *operator new(size_t);
    void operator delete(void *m);
};

unsigned char Framis::pool[psize * sizeof(Framis)];
bool Framis::alloc_map[psize] = {false};

// Size is ignored -- assume a Framis object
void *Framis::operator new(size_t)
{
    for (int i = 0; i < psize; i++)
    {
        if (!alloc_map[i])
        {
            out << "using block " << i << " ... ";
            alloc_map[i] = true; // Mark it used

            return pool + (i * sizeof(Framis));
        }
    }

    out << "out of memory" << std::endl;
    throw std::bad_alloc();
}

void Framis::operator delete(void *m)
{
    if (!m)
    {
        return; // Check for null pointer
    }

    // Assume it was created in the pool
    // Calculate which block number it is:
    unsigned long block = (unsigned long)m - (unsigned long)pool;
    block /= sizeof(Framis);

    out << "freeing block " << block << std::endl;

    // Mark it free:
    alloc_map[block] = false;
}

#endif // FRAMIS_H