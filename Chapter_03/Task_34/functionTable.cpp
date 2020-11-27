#include <iostream>
#include <string>

// A macro to define dummy functions:
#define DF(N)                               \
    std::string N()                         \
    {                                       \
        return "function " #N " called..."; \
    }

DF(a);
DF(b);
DF(c);
DF(d);
DF(e);
DF(f);
DF(g);

std::string (*func_table[])() = {a, b, c, d, e, f, g};
int main()
{
    while (1)
    {
        std::cout << "press a key from 'a' to 'g' "
                     "or q to quit"
                  << std::endl;
        char c, cr;
        std::cin.get(c);
        std::cin.get(cr); // second one for CR
        if (c == 'q')
            break; // ... out of while(1)
        if (c < 'a' || c > 'g')
            continue;
        std::cout << (*func_table[c - 'a'])() << std::endl;
    }
}