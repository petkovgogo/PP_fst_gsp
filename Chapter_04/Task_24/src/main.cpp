#include "../inc/LinkedList.h"

int main()
{
    const int SIZE = 8;
    LinkedList linkedList;
    createList(linkedList, SIZE);

    printList(linkedList);
    cleanup(linkedList);

    return 0;
}
