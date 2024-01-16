#include <iostream>
#include "Structures/LinkedList/LinkedList.h"

int main() {
    cout << "Hello, World!" << endl;

    LinkedList<int> l = LinkedList<int>();
    l.print();
    l.insert(5, l.begin());
    l.insert(4, l.begin());
    l.insert(6, l.last());
    l.print();

    return 0;
}

/*
 * TODO: LinkedList, ListVector, Stack (Pila), Queue, Dictionary, TreeBin, TreeNary, PriorityQueue
 */
