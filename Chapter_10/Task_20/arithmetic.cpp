#include "NamespaceInt.h"

void arithmetic()
{
    using namespace Int;
    Integer x;
    x.setSign(positive);
}

int main()
{
    // Integer num; // error: ‘Integer’ was not declared in this scope; did you mean ‘Int::Integer’
}