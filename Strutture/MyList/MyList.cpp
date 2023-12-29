#include "MyList.h"

template<class T>
MyList<T>::MyList() = default;

template<class T>
MyList<T>::~MyList() = default;

template<class T>
bool MyList<T>::isEmpty() const {
    for (int i = 0; i < length; i++) {
        if (elements[i] != nullptr) {
            return false;
        }
    }
    return true;
}

template<class T>
bool MyList<T>::isEnd(int pos) const {
    for (int i = pos; i < length; i++) {
        if (elements[i] != nullptr) {
            return false;
        }
    }
    return true;
}

template<class T>
int MyList<T>::getNext(int pos) const {
    if (pos < length && elements[pos + 1] != nullptr) {
        return pos + 1;
    }
    return -1;
}

template<class T>
int MyList<T>::getPrevious(int pos) const {
    if (pos > 0 && elements[pos - 1] != nullptr) {
        return pos - 1;
    }
    return -1;
}

template<class T>
T MyList<T>::read(int pos) const {
    return elements[pos];
}

template<class T>
void MyList<T>::insert(T elem, int pos) {
    // TODO: Check if pos is void, if not move everything to the right
    elements[pos] = elem;
}

template<class T>
void MyList<T>::remove(int pos) {
    // TODO: Check if pos is void, if not move everything to the right
    elements[pos] = nullptr;
}


template<class T>
bool MyList<T>::isPosValid(int pos) {

}

template<class T>
void MyList<T>::cleanList() {
    for (int i = 0; i < length; i++) {
        if (elements[i] != nullptr) {

        }
    }
}