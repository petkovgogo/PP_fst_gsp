#include <iostream>

enum VarType
{
    character,
    integer,
    floating_point
};

class SuperVar
{
#ifdef ENUMERATED

    VarType vartype; // Define one

#endif // ENUMERATED

    union
    { // Anonymous union
        char c;
        int i;
        float f;
    };

public:
    SuperVar(char ch);
    SuperVar(int ii);
    SuperVar(float ff);
#ifdef ENUMERATED

    void print();

#else

    void print(VarType vartype);

#endif // ENUMERATED
};

SuperVar::SuperVar(char ch)
{
#ifdef ENUMERATED

    vartype = character;

#endif // ENUMERATED

    c = ch;
}

SuperVar::SuperVar(int ii)
{
#ifdef ENUMERATED

    vartype = integer;

#endif // ENUMERATED

    i = ii;
}

SuperVar::SuperVar(float ff)
{
#ifdef ENUMERATED

    vartype = floating_point;

#endif // ENUMERATED

    f = ff;
}

#ifdef ENUMERATED

void SuperVar::print()

#else

void SuperVar::print(VarType vartype)

#endif // ENUMERATED
{
    switch (vartype)
    {
    case character:
        std::cout << "character: " << c << std::endl;
        break;
    case integer:
        std::cout << "integer: " << i << std::endl;
        break;
    case floating_point:
        std::cout << "float: " << f << std::endl;
        break;
    }
}

int main()
{
    SuperVar A('c'), B(12), C(1.44F);

#ifdef ENUMERATED

    A.print();
    B.print();
    C.print();

#else

    A.print(character);
    B.print(integer);
    C.print(floating_point);

#endif // ENUMERATED

    return 0;
}