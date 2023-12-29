#include <iostream>
#include "MyList.h"

using namespace std;

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
    if (!isPosValid(pos)) {
        throw;
    }
    for (int i = pos; i < length; i++) {
        if (elements[i] != nullptr) {
            return false;
        }
    }
    return true;
}

template<class T>
int MyList<T>::getNext(int pos) const {
    if (isPosValid(pos) && elements[pos + 1] != nullptr) {
        return pos + 1;
    }
    return -1;
}

template<class T>
int MyList<T>::getPrevious(int pos) const {
    if (isPosValid(pos) && elements[pos - 1] != nullptr) {
        return pos - 1;
    }
    return -1;
}

template<class T>
T MyList<T>::read(int pos) const {
    return elements[pos];
}

template<class T>
void MyList<T>::write(T elem, int pos) {
    if (isPosValid(pos)) {
        elements[pos] = elem;
        cleanList();
    }
}

template<class T>
void MyList<T>::insert(T elem, int pos) {
    if (isPosValid(pos)) {
        for (int i = 0; i < length; ++i) {
            //TODO: Move everything to the right
        }
        elements[pos] = elem;
        cleanList();
    }
}

template<class T>
void MyList<T>::remove(int pos) {
    if (isPosValid(pos)) {
        elements[pos] = nullptr;
        cleanList();
    }
}


template<class T>
bool MyList<T>::isPosValid(int pos) {
    if (pos < 0 || pos > length) {
        return false;
    }
    return true;
}

template<class T>
void MyList<T>::cleanList() {
    bool modified = false;
    T prevElem;
    T currElem;

    for (int i = 1; i < length; i++) {
        prevElem = elements[i - 1];
        currElem = elements[i];
        if (prevElem == nullptr && currElem != nullptr) {
            modified = true;
            elements[i - 1] = currElem;
            elements[i] = prevElem;
        }
    }
    if (modified) {
        cleanList();
    }
}

template<class T>
void MyList<T>::print() {
    cout << "[";
    for (int i = 0; i < length; ++i) {
        while (!isEnd(i)) {
            cout << elements[i] << ", ";
        }
    }
    cout << "]" << endl;
}