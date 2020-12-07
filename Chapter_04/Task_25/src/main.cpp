#include "../inc/LinkedList.h"
#include "../inc/ListFunc.h"

int main()
{
    const int SIZE = 8;
    LinkedList linkedList;
    ListFunc::createList(linkedList, SIZE);

    ListFunc::printList(linkedList);
    ListFunc::cleanup(linkedList);

    return 0;
}
