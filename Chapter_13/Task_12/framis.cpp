#include <iostream>
#include <fstream>
#include <ctime>
#include <new>

std::ofstream out("Framis.out.txt");

class Framis
{
    enum { sz = 10 };

    char c[sz]; // To take up space, not used

    static unsigned char pool[];
    static bool alloc_map[];

public:
    enum { psize = 100 }; // frami allowed

    Framis() { out << "Framis()\n"; }
    ~Framis() { out << "~Framis() ... "; }

#ifdef OVERLOAD_OP

    void *operator new(size_t);
    void operator delete(void *);

#endif // OVERLOAD_OP
};

unsigned char Framis::pool[psize * sizeof(Framis)];
bool Framis::alloc_map[psize] = {false};

#ifdef OVERLOAD_OP
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

#endif // OVERLOAD_OP

int main()
{
    Framis *f[Framis::psize];

    clock_t executionTime = clock();

    try
    {
        for (int i = 0; i < Framis::psize; i++)
        {
            f[i] = new Framis;
        }

        new Framis; // Out of memory
    }
    catch (std::bad_alloc &)
    {
        std::cerr << "Out of memory!" << std::endl;
    }

    delete f[10];
    f[10] = 0;

    // Use released memory:
    Framis *x = new Framis;
    delete x;

    for (int j = 0; j < Framis::psize; j++)
    {
        delete f[j]; // Delete f[10] OK
    }

    executionTime = clock() - executionTime;

    std::cout << "Time for execution: " << ((double) executionTime / CLOCKS_PER_SEC) << std::endl;
}