#include <iostream>
#include "Structures/LinkedList/LinkedList.h"
#include "Structures/ListVector/ListVector.h"
#include "Structures/Stack/Stack.h"
#include "Structures/Queue/Queue.h"
//#include "Structures/Dictionary/Dictionary.h"
//#include "Structures/Dictionary/HashTable.h"

int main() {
    cout << "Hello, World!" << endl;

    cout << "Linked List:" << endl;
    LinkedList<int> l = LinkedList<int>();
    cout << l << endl;
    l.insert(5, l.begin());
    l.insert(4, l.begin());
    l.insert(6, l.last());
    cout << l << endl;

    cout << "Linked List 1:" << endl;
    LinkedList<int> l1 = LinkedList<int>(3);
    cout << l1 << endl;
    l1.insert(5, l1.begin());
    cout << l1 << endl;
    l1.write(1, l1.begin());
    cout << l1 << endl;

    cout << "Linked List 2:" << endl;
    LinkedList<char> l2 = LinkedList<char>(3);
    cout << l2 << endl;
    l2.insert('a', l2.begin());
    cout << l2 << endl;

    cout << "List Vector:" << endl;
    ListVector<int> vl = ListVector<int>();
    cout << vl << endl;
    vl.insert(4, vl.begin());
    vl.insert(3, vl.begin());
    cout << vl << endl;
    vl.write(2, vl.begin());
    cout << vl << endl;

    cout << "Stack:" << endl;
    Stack<int> s = Stack<int>();
    cout << s << endl;
    s.insert(4);
    s.insert(3);
    cout << s << endl;
    cout << s.read() << endl;
    s.removeLast();
    cout << s << endl;

    cout << "Queue:" << endl;
    Queue<int> q = Queue<int>(100);
    cout << q << endl;
    q.insert(4);
    q.insert(3);
    cout << q << endl;
    cout << q.read() << endl;
    q.removeFirst();
    cout << q << endl;

    cout << "Dictionary:" << endl;
//    HashTable<char, int> d = HashTable<char, int>(5);
/*

    MyPair<char, int> p0;
    p0.first = 'a';
    p0.second = 1;
    cout << p0.first << endl;
    cout << p0.second << endl;

    MyPair<char, int> p1 = MyPair<char, int>('b', 2);
    cout << p1.first << endl;
    cout << p1.second << endl;

//    cout << d.size() << endl;
//    d.insert(p0);
//    d.insert(p1);
//    cout << d.size() << endl;
//    cout << d. << endl;
//    cout << d. << endl;
*/

    cout << "Binary Tree:" << endl;


    cout << "N-Ary Tree:" << endl;


    cout << "Priority Queue:" << endl;


    return 0;
}

/*
 * TODO: LinkedList, ListVector, Stack (Stack), Queue, Dictionary, TreeBin, TreeNary, PriorityQueue
 */
