#include <iostream>
#include "Structures/LinkedList/LinkedList.h"
#include "Structures/ListVector/ListVector.h"
#include "Structures/Stack/Stack.h"
#include "Structures/Queue/Queue.h"
#include "Structures/Dictionary/Dictionary.h"
#include "Structures/Dictionary/HashTable.h"
#include "Structures/BinTree/Bin_treec.h"
#include "Structures/TreeList/TreeList.h"

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
    HashTable<char, int> d = HashTable<char, int>(5);

    MyPair<char, int> p0;
    p0.key = 'a';
    p0.element = 1;
    cout << "Key: " << p0.key << ", Element:" << p0.element << endl;

    MyPair<char, int> p1 = MyPair<char, int>('b', 2);
    cout << "Key: " << p1.key << ", Element:" << p1.element << endl;

    cout << d << endl;
    d.insert(p0);
    d.insert(p1);
    cout << d << endl;
    cout << *d.find(p0.key) << endl;

    HashTable<int, int> d1 = HashTable<int, int>(5);
    MyPair<int, int> p2 = MyPair<int, int>(1, 1);
    MyPair<int, int> p3 = MyPair<int, int>(2, 2);
    MyPair<int, int> p4 = MyPair<int, int>(2, 3);
    cout << d1 << endl;
    d1.insert(p2);
    d1.insert(p3);
    d1.insert(p4);
    cout << d1 << endl;
    cout << *d1.find(p2.key) << endl;
    cout << *d1.find(2) << endl;

    cout << "Binary tree:" << endl;
    Bin_treec<int> T;
    typename Bin_treec<int>::Nodo n1 = 0;
    typename Bin_treec<int>::Nodo n2 = 0;

    T.ins_root();
    T.write(T.root(), 1);
    n1 = T.root();
    T.ins_sx(n1);
    T.ins_dx(n1);
    T.write(T.sx(n1), 2);
    n1 = T.dx(n1);
    T.write(n1, 3);
    T.ins_dx(n1);
    T.write(T.dx(n1), 4);
    cout << T << endl;
    T.printBT(T.root());

    cout << "N-Ary tree:" << endl;
    TreeList<char> tree;

    TreeList<char>::node n;
    tree.insRoot(n);
    tree.writeNode(tree.root(), 'a');

    tree.insFirst(tree.root(), 'b');
    tree.insFirst(tree.root(), 'c');

    n = tree.root();
    n = tree.firstChild(n);

    tree.ins(n, 'd');

    n = tree.root();
    n = tree.firstChild(n);
    tree.insFirst(n, 'e');
    tree.insFirst(n, 'f');

    tree.print();

    n = tree.root();
    n = tree.firstChild(n);
    tree.removeSubTree(n);

    tree.print();

    cout << "Priority Queue:" << endl;


    return 0;
}

/*
 * TODO: LinkedList, ListVector, Stack (Stack), Queue, Dictionary, BinTree, TreeList, PriorityQueue
 */
