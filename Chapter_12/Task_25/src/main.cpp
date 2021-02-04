#include "../inc/Integer.h"
#include <fstream>

std::ofstream out("../out/IntegerTest.out.txt");

void f(Integer a)
{
#define TRYU(EXP)             \
    out << #EXP " produces "; \
    out << EXP;               \
    out << std::endl;

    TRYU(+a;)
    TRYU(-a;)
    TRYU(~a;)
    Integer *ip;
    TRYU(*(ip = &a))
    TRYU(!a;)
    TRYU(++a);
    TRYU(a++);
    TRYU(--a);
    TRYU(a--);
}

void h(Integer &c1, Integer &c2)
{
    // A complex expression:
    c1 += c1 * c2 + c2 % c1;

#define TRY(OP)                         \
    out << "c1 = " << c1;               \
    out << ", c2 = " << c2;             \
    out << "; c1 " #OP " c2 produces "; \
    out << (c1 OP c2);                  \
    out << std::endl;

    TRY(+)
    TRY(-)
    TRY(*)
    TRY(/)
    TRY(%)
    TRY(^)
    TRY(&)
    TRY(|)
    TRY(<<)
    TRY(>>)
    TRY(+=)
    TRY(-=)
    TRY(*=)
    TRY(/=)
    TRY(%=)
    TRY(^=)
    TRY(&=)
    TRY(|=)
    TRY(>>=)
    TRY(<<=)

    // Conditionals:
#define TRYC(OP)                        \
    out << "c1 = " << c1;               \
    out << ", c2 = " << c2;             \
    out << "; c1 " #OP " c2 produces "; \
    out << (c1 OP c2);                  \
    out << std::endl;

    TRYC(<)
    TRYC(>)
    TRYC(==)
    TRYC(!=)
    TRYC(<=)
    TRYC(>=)
    TRYC(&&)
    TRYC(||)
}

int main()
{
    /**
     * NOTE: 
     *  operator& is called by every assignment operator (e.g. +=, *=, ^=, etc.),
     * so &Integer will be printed in the console many times
    **/

    std::cout << "friend functions" << std::endl;

    Integer c1(42);
    Integer c2(451);

    h(c1, c2);
    f(c1);

    return 0;
}