#include "LinkedList/MyLinkedList.h"

using namespace std;

int main() {
    MyLinkedList<int> l = MyLinkedList<int>(5);
    l.addNext(MyLinkedList(15));
    /*
    MyLinkedList<int> l1 = l.getNext();
    x = 32;
    l1.addNext(MyLinkedList(x));

    l.print();
     */

    return 0;
}
