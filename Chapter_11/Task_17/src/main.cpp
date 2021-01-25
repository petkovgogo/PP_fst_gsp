#include "../inc/DynamicDouble.h"

void passByValue(DynamicDouble copyDouble) { copyDouble.print(); }

int main()
{
    DynamicDouble originalDD(3.14);

    // The problem is the synthesized copy-constructor does not allocate
    // new dynamic storage, which is why the original is deleted when the copyDouble's
    // destructor is called. So when the originalDD's destructor is called, it attempts
    // to delete an invalid storage, which leads to an error
    passByValue(originalDD);

    return 0;
}