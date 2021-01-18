#include "../inc/LinkedList.h"

int main()
{
    const int SIZE = 8;

    LinkedList linkedList;
    
    LinkedList::createList(linkedList, SIZE);
    LinkedList::printList(linkedList);
    LinkedList::cleanup(linkedList);

    return 0;
}
