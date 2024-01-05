#ifndef ALGORITMI_LAB_MYLIST_H
#define ALGORITMI_LAB_MYLIST_H

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MyListVector {
private:
    vector<T> elements;

    int getNext(int pos) const;

    int getPrevious(int pos) const;

    bool isPosValid(int pos) const;

    void cleanList();

public:
    MyListVector();

    ~MyListVector();

    /// Returns true if empty
    bool isEmpty() const;

    /// Checks if this is the end of the list
    /// Doesn't check if the current position is not valid
    bool isEnd(int pos) const;

    /// Reads value of position, -1 if void
    T read(int pos) const;

    /// Writes in the lat position
    void add(T elem);

    /// Overwrites position, if present
    void write(T elem, int pos);

    /// Insert element in position, moves everything else to the right
    void insert(T elem, int pos);

    /// Removes value of position
    void remove(int pos);

    /// Prints list
    void print() const;
};

template<class T>
MyListVector<T>::MyListVector() = default;

template<class T>
MyListVector<T>::~MyListVector() = default;

template<class T>
bool MyListVector<T>::isEmpty() const {
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i] != -1) {
            return false;
        }
    }
    return true;
}

template<class T>
bool MyListVector<T>::isEnd(int pos) const {
    //if (!isPosValid(pos)) {
    //    throw;
    //}
    for (int i = pos; i < elements.size(); i++) {
        if (elements[i] != -1) {
            return false;
        }
    }
    return true;
}

template<class T>
int MyListVector<T>::getNext(int pos) const {
    if (isPosValid(pos)) {
        return pos + 1;
    }
    return -1;
}

template<class T>
int MyListVector<T>::getPrevious(int pos) const {
    if (isPosValid(pos) && elements[pos - 1] != -1) {
        return pos - 1;
    }
    return -1;
}

template<class T>
T MyListVector<T>::read(int pos) const {
    return elements[pos];
}

template<class T>
void MyListVector<T>::add(T elem) {
    elements.push_back(elem);
}

template<class T>
void MyListVector<T>::write(T elem, int pos) {
    if (isPosValid(pos)) {
        elements[pos] = elem;
        cleanList();
    }
}

template<class T>
void MyListVector<T>::insert(T elem, int pos) {
    MyListVector<T> tmp;
    int j = 0;
    if (isPosValid(pos)) {
        tmp.write(elem, j);
        j++;
        for (int i = pos; i < elements.size() - 1; ++i) {
            tmp.write(this->read(i), j);
            j++;
        }

        j = 0;
        for (int i = pos; i < tmp.elements.size(); ++i) {
            this->write(tmp.read(j), i);
            j++;
        }

        elements[pos] = elem;
        cleanList();
    }
}

template<class T>
void MyListVector<T>::remove(int pos) {
    if (isPosValid(pos)) {
        elements[pos] = -1;
        cleanList();
    }
}


template<class T>
bool MyListVector<T>::isPosValid(int pos) const {
    if (pos < 0 || pos >= elements.size()) {
        return false;
    }
    return true;
}

template<class T>
void MyListVector<T>::cleanList() {
    bool modified = false;
    T prevElem;
    T currElem;

    for (int i = 1; i < elements.size(); i++) {
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
void MyListVector<T>::print() const {
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
