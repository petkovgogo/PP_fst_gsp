#include <fstream>

extern std::ofstream out; // Trace file

class Obj
{
    char c; // Identifier

public:
    Obj(char cc) : c(cc)
    {
        out << "Obj::Obj() for " << c << std::endl;
    }
    ~Obj()
    {
        out << "Obj::~Obj() for " << c << std::endl;
    }
};

Obj a('a'); // Global (static storage)
// Constructor & destructor always called

std::ofstream out("statdest.out"); // Definition moved here

void f()
{
    static Obj b('b');
}

void g()
{
    static Obj c('c');
}

int main()
{
    out << "inside main()" << std::endl;

    f(); // Calls static constructor for b
    // g() not called

    out << "leaving main()" << std::endl;

    return 0;
}