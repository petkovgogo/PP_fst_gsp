#include "../inc/LinkedList.h"

int main()
{
    const int SIZE = 8;
    LinkedList linkedList;
    LinkedListFunc::createList(linkedList, SIZE);

    LinkedListFunc::printList(linkedList);
    LinkedListFunc::cleanup(linkedList);

    return 0;
}
