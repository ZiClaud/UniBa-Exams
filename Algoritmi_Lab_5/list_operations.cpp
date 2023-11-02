#include "list_operations.h"

template<class T>
int List_Operations<T>::lunghezza(list<T> l) {
    return l.size();
}

template<class T>
void List_Operations<T>::inverti(list<T> &l) {
    l.reverse();
}

template<class T>
bool List_Operations<T>::palindoma(list<T> l) {
    T item;
    for (int i = 0; i < lunghezza(l); ++i) {
        if (l[i] != l[lunghezza(l) - i]) {
            return false;
        }
    }

    return true;
}
