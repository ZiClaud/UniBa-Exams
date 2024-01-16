#include <iostream>
#include "Structures/LinkedList/LinkedList.h"

int main() {
    cout << "Hello, World!" << endl;

    LinkedList<int> l = LinkedList<int>();
    cout << l << endl;
    l.insert(5, l.begin());
    l.insert(4, l.begin());
    l.insert(6, l.last());
    cout << l << endl;
    cout << l << endl;

    return 0;
}

/*
 * TODO: LinkedList, ListVector, Stack (Pila), Queue, Dictionary, TreeBin, TreeNary, PriorityQueue
 */
