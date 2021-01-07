#include <fstream>

#define BAND(x) (((x) > 5 && (x) < 10) ? (x) : 0)

int main()
{
    std::ofstream out("macro.out.txt");

    for (int i = 4; i < 11; i++)
    {
        int a = i;

        out << "a = " << a++ << std::endl; // incremented a here, instead of in the macro (same result)
        out << "\tBAND(++a) = " << BAND(a) << std::endl;
        out << "\t a = " << a << std::endl;
    }

    return 0;
}