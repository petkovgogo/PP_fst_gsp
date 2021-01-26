#include <iostream>

#define PRINT(EXP) \
    std::cout << #EXP " -> " << EXP << std::endl;

class Simple2
{
public:
    int f(float) const { return 1; }
    int f(char) const { return 42; }
};

typedef int (Simple2::*ffPtr_t)(float) const;
typedef int (Simple2::*fcPtr_t)(char) const;

int main()
{
    //  The overload resolution in this case happens via
    // the different argument lists of the types ffPtr_t and fcPtr_t

    ffPtr_t ffp = &Simple2::f;
    fcPtr_t fcp = &Simple2::f;

    Simple2 simple2Obj;

    PRINT((simple2Obj.*ffp)(3.14F));
    PRINT((simple2Obj.*fcp)('*'));

    return 0;
}