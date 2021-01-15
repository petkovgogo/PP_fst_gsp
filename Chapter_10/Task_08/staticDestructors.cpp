#include <fstream>

std::ofstream out("outputs/g() called before f().txt"); // Trace file

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

void f()
{
    static Obj b('b');
}

void g()
{
    static Obj c('c');
}

// The compiler calls the constructors in the order the objects are created and the destructors in reverse order

int main()
{
    out << "inside main()" << std::endl;
    
    g();
    f();

    out << "leaving main()" << std::endl;

    return 0;
}