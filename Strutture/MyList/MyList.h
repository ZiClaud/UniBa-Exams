#ifndef ALGORITMI_LAB_MYLIST_H
#define ALGORITMI_LAB_MYLIST_H

#include <iostream>

using namespace std;

template<class T>
class MyList {
private:
    T elements[1024];
    int length = 1024;

    bool isPosValid(int pos) const;

    void cleanList();

public:
    MyList();

    ~MyList();

    bool isEmpty() const;

    bool isEnd(int pos) const;

    int getNext(int pos) const;

    int getPrevious(int pos) const;

    T read(int pos) const;

    void write(T elem, int pos);

    void insert(T elem, int pos);

    void remove(int pos) const;

    void print() const;
};

template<class T>
MyList<T>::MyList() {
    for (int i = 0; i < length; ++i) {
        elements[i] = -1;
    }
};

template<class T>
MyList<T>::~MyList() = default;

template<class T>
bool MyList<T>::isEmpty() const {
    for (int i = 0; i < length; i++) {
        if (elements[i] != -1) {
            return false;
        }
    }
    return true;
}

template<class T>
bool MyList<T>::isEnd(int pos) const {
//    if (!isPosValid(pos)) {
//        throw;
//    }
    for (int i = pos; i < length; i++) {
        if (elements[i] != -1) {
            return false;
        }
    }
    return true;
}

template<class T>
int MyList<T>::getNext(int pos) const {
    if (isPosValid(pos) && elements[pos + 1] != -1) {
        return pos + 1;
    }
    return -1;
}

template<class T>
int MyList<T>::getPrevious(int pos) const {
    if (isPosValid(pos) && elements[pos - 1] != -1) {
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
    MyList<T> tmp;
    int j = 0;
    if (isPosValid(pos)) {
        tmp.write(elem, j);
        j++;
        for (int i = pos; i < length - 1; ++i) {
            tmp.write(this->read(i), j);
            j++;
        }

        j = 0;
        for (int i = pos; i < tmp.length; ++i) {
            this->write(tmp.read(j), i);
            j++;
        }

        elements[pos] = elem;
        cleanList();
    }
}

template<class T>
void MyList<T>::remove(int pos) const {
    if (isPosValid(pos)) {
        elements[pos] = -1;
        cleanList();
    }
}


template<class T>
bool MyList<T>::isPosValid(int pos) const {
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
        if (prevElem == -1 && currElem != -1) {
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
void MyList<T>::print() const {
    cout << "[";
    int pos = 0;
    while (this->getNext(pos) != -1) {
        cout << elements[pos];
        cout << ", ";
        pos++;
    }
    if (pos != 0 || !isEnd(pos)) {
        cout << elements[pos];
    }
    cout << "]" << endl;
}

#endif //ALGORITMI_LAB_MYLIST_H
