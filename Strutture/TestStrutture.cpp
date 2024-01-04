#include <iostream>
#include "MyList/MyList.h"

using namespace std;

int main() {
    cout << "Hello" << endl;
    MyList<int> l;
    l.print();
    l.write(1, 0);
    l.write(2, 1);
    l.write(3, 2);
    l.write(5, 8);
    l.write(12, 23);
    l.print();
    cout << l.read(2);
//    l.insert(15, 0);
//    l.insert(15, 1);
//    l.insert(15, 2);
    /*
    MyLinkedList<int> l1 = l.getNext();
    x = 32;
    l1.addNext(MyLinkedList(x));

    l.print();
     */

    return 0;
}
