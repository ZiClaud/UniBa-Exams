#include <iostream>
#include "MyListVector/MyListVector.h"

using namespace std;

int main() {
    ///Test MyListVector
    cout << "Hello" << endl;
    MyListVector<int> l;
    l.print();
    cout << "IsEnd(2):" << l.isEnd(2) << endl;
    cout << "IsEmpty:" << l.isEmpty() << endl;
    // TODO: Test without "add" first
    l.add(4);
    l.add(3);
    l.add(2);
    l.add(1);
    l.print();
    l.write(1, 0);
    l.write(2, 1);
    l.write(3, 2);
    l.write(5, 8);
    l.write(12, 23);
    l.print();
    cout << l.read(2) << endl;
    l.write(16, 1);
    l.print();
    l.insert(32, 1);
    l.print();
    l.insert(64, 0);
    l.print();
    l.remove(0);
    l.print();
    cout << "IsEnd(2):" << l.isEnd(2) << endl;
    cout << "IsEnd(24):" << l.isEnd(24) << endl;
    cout << "IsEmpty:" << l.isEmpty() << endl;

    ///Test MyStack (Pila)

    return 0;
}
