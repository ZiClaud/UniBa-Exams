#include <iostream>
#include "Structures/LinkedList/LinkedList.h"
#include "Structures/ListVector/ListVector.h"
#include "Structures/Stack/Stack.h"
#include "Structures/Queue/Queue.h"

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
    l1.write(1, l1.begin());
    cout << l1 << endl;

    cout << "l2" << endl;
    LinkedList<char> l2 = LinkedList<char>(3);
    cout << l2 << endl;
    l2.insert('a', l2.begin());
    cout << l2 << endl;

    cout << "vl" << endl;
    ListVector<int> vl = ListVector<int>();
    cout << vl << endl;
    vl.insert(4, vl.begin());
    vl.insert(3, vl.begin());
    cout << vl << endl;
    vl.write(2, vl.begin());
    cout << vl << endl;

    cout << "s" << endl;
    Stack<int> s = Stack<int>();
    cout << s << endl;
    s.insert(4);
    s.insert(3);
    cout << s << endl;
    cout << s.read() << endl;
    s.removeLast();
    cout << s << endl;

    cout << "q" << endl;
    Queue<int> q = Queue<int>(100);
    cout << q << endl;
    q.insert(4);
    q.insert(3);
    cout << q << endl;
    cout << q.read() << endl;
    q.removeFirst();
    cout << q << endl;

    return 0;
}

/*
 * TODO: LinkedList, ListVector, Stack (Stack), Queue, Dictionary, TreeBin, TreeNary, PriorityQueue
 */
