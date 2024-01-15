//
// Created by ziclaud on 15/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_LINKEDLIST_H
#define ASD_EXAM_STRUCTURES_LINKEDLIST_H

template<class T>
class Node {
public:
    T data;
    Node<T> *next;
    Node<T> *prev;
};

template<class T>
class LinkedList {
public:
    LinkedList();

    ~LinkedList();

    bool isEmpty();

    T readElem(Node<T> node);

    // Overrides the value
    void writeElem(T elem, Node<T> node);

    bool isEnd(Node<T> node);

    Node<T> getStart();

    Node<T> getEnd();

    Node<T> getNext(Node<T> node);

    Node<T> getPrev(Node<T> node);

    // Inserts the value
    void insert(T elem, Node<T> node);

    void remove(Node<T> node);

    // TODO: Operator =

    bool operator==(const LinkedList<T> &) const;

    // TODO: Operator !=
};


#endif //ASD_EXAM_STRUCTURES_LINKEDLIST_H
