#include <iostream>
#include "Structures/LinkedList/LinkedList.h"

int main() {
    cout << "Hello, World!" << endl;

    cout << "l" << endl;

    LinkedList<int> l = LinkedList<int>();
    cout << l << endl;
    l.insert(5, l.begin());
    l.insert(4, l.begin());
    l.insert(6, l.last());
    cout << l << endl;

    cout << "l1" << endl;

    LinkedList<int> l1 = LinkedList<int>(3);
    cout << l1 << endl;
    l1.insert(5, l1.begin());
    cout << l1 << endl;

    cout << "l2" << endl;

    LinkedList<char> l2 = LinkedList<char>(3);
    cout << l2 << endl;
    l2.insert('a', l2.begin());
    cout << l2 << endl;

    return 0;
}

/*
 * TODO: LinkedList, ListVector, Stack (Pila), Queue, Dictionary, TreeBin, TreeNary, PriorityQueue
 */
