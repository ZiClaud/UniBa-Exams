#include <iostream>
#include "MyLinkedList.h"

using namespace std;

/*
template<class T>
MyLinkedList<T>::MyLinkedList(T value) {
    val = value;
}
*/

template<class T>
MyLinkedList<T> MyLinkedList<T>::getNext() {
    return next;
}

template<class T>
MyLinkedList<T> MyLinkedList<T>::getPrev() {
    return prev;
}


template<class T>
void MyLinkedList<T>::addNext(MyLinkedList<T> list) {
    next = &list;
}

template<class T>
void MyLinkedList<T>::addPrev(MyLinkedList<T> list) {
    prev = &list;
}

template<class T>
void MyLinkedList<T>::removeNext() {
}

template<class T>
void MyLinkedList<T>::removePrev() {
}

template<class T>
void MyLinkedList<T>::print() {
    MyLinkedList<T> l = this;
    int i = 0;
    do {
        i++;
        cout << "Value " << i << ": " << val << endl;

        l = l.getNext();
    } while (l != nullptr || l.next != nullptr || l == this);
}
