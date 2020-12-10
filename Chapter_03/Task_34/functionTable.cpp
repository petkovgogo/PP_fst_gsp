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
    char c;

    while (true)
    {
        std::cout << "press a key from 'a' to 'g' "
                     "or q to quit"
                  << std::endl;
        std::cin.get(c);
        std::cin.get(); // second one for new line
        
        if (c == 'q')
        {
            break;
        }

        if (c < 'a' || c > 'g')
        {
            continue;
        }

        std::cout << (*func_table[c - 'a'])() << std::endl;
    }

    return 0;
}