#include "Func1.h"
#include "Func2.h"

namespace polite_funcs = namespaceWithAReallyLongName;

void introduceOdd()
{
    polite_funcs::func1();
    polite_funcs::func3();
    polite_funcs::func5();
}

void introduceEven()
{
    using namespace polite_funcs;

    func2();
    func4();
    func6();
}

int main()
{
    introduceOdd();
    introduceEven();

    return 0;
}