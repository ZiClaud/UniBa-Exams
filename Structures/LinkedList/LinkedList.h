//
// Created by ziclaud on 15/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_LINKEDLIST_H
#define ASD_EXAM_STRUCTURES_LINKEDLIST_H

#include "LinearList.h"

template<class T>
class LinkedList;

template<class T>
class ListNode {
    friend class LinkedList<T>;

private:
    T _value;
    ListNode<T> *_pPrev;
    ListNode<T> *_pNext;
};

template<class T>
class LinkedList : public LinearList<T, ListNode<T> *> {
private:
    ListNode<T> *_pHead;
    int _length = 0; // the length of the list
public:
    typedef typename LinearList<T, ListNode<T> *>::value_type value_type;
    typedef typename LinearList<T, ListNode<T> *>::position position;

    // costruttori
    LinkedList();

    LinkedList(int);

    // costruttore per copia
    LinkedList(const LinkedList<T> &);

    //distruttore
    ~LinkedList();

    bool empty() const;

    value_type read(position) const;

    void write(const value_type &, position);

    position begin() const;

    position last() const;

    bool end(position) const;

    position next(position) const;

    position previous(position) const;

    void insert(const value_type &, position);

    void erase(position);

    int size() const {
        return _length;
    };

    // sovraccarico di operatori
    LinkedList<T> &operator=(const LinkedList<T> &); // the assignment operator
    bool operator==(const LinkedList<T> &) const; // tests two list for equality
};

template<class T>
LinkedList<T>::LinkedList() {
    _pHead = new ListNode<T>;
    _pHead->_pNext = _pHead;
    _pHead->_pPrev = _pHead;
    _length = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &L) {
    _pHead = new ListNode<T>;
    _pHead->_pNext = _pHead;
    _pHead->_pPrev = _pHead;

    if (!L.empty()) {
        position p = L.last();
        for (int i = 0; i <= L._length; i++) {
            insert(L.read(p), begin());
            p = L.previous(p);
        }
    }
}


template<class T>
LinkedList<T>::~LinkedList() {
    while (!empty())
        erase(begin());
    delete _pHead;
}

template<class T>
bool LinkedList<T>::empty() const {
    return (_pHead == _pHead->_pNext);
}

template<class T>
typename LinkedList<T>::position
LinkedList<T>::begin() const {
    return (_pHead->_pNext);
}

template<class T>
typename LinkedList<T>::position
LinkedList<T>::last() const {
    return (_pHead->_pPrev);
}


template<class T>
typename LinkedList<T>::position
LinkedList<T>::next(position p) const {
    return (p->_pNext);
}

template<class T>
typename LinkedList<T>::position LinkedList<T>::previous(position p) const {
    if (p != _pHead)
        return (p->_pPrev);
}

template<class T>
bool LinkedList<T>::end(position p) const {
    return (p == _pHead);
}

template<class T>
typename LinkedList<T>::value_type
LinkedList<T>::read(position p) const {
    if (!end(p))
        return (p->_value);
}

template<class T>
void LinkedList<T>::write(const value_type &a, position p) {
    if (!end(p))
        p->_value = a;
}

template<class T>
void LinkedList<T>::insert(const value_type &a, position p) {
    position t = new ListNode<T>;
    t->_value = a;

    t->_pNext = p;
    t->_pPrev = p->_pPrev;
    p->_pPrev->_pNext = t;
    p->_pPrev = t;

    _length++;
}

template<class T>
void LinkedList<T>::erase(position p) {
    if (!empty() && !end(p)) {
        p->_pPrev->_pNext = p->_pNext;
        p->_pNext->_pPrev = p->_pPrev;
        delete p;
        _length--;
    }
}


template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &L) {
    if (this != &L) {

        // deallocare tutta la lista this

        ~LinkedList();

        //_length = L.size();

        _pHead = new ListNode<T>;
        _pHead->_pNext = _pHead;
        _pHead->_pPrev = _pHead;

        cout << L.empty();
        cout << L.size();
        if (!L.empty()) {
            position p = L.last();
            for (int i = 0; i < L.size(); i++) {
                cout << i, L.read(p);
                insert(L.read(p), begin());
                p = L.previous(p);
            }
        }
    }
    return *this;
}


template<class T>
bool LinkedList<T>::operator==(const LinkedList<T> &L) const {
    if (L.size() != _length)
        return false;
    position p, pL;
    p = begin();
    pL = L.begin();
    while (!end(p)) {
        if (p->_value != pL->_value)
            return false;
        p = p->_pNext;
        pL = pL->_pNext;
    }
    return true;
}

#endif //ASD_EXAM_STRUCTURES_LINKEDLIST_H
