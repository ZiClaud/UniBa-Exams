//
// Created by ziclaud on 15/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_LINKEDLIST_H
#define ASD_EXAM_STRUCTURES_LINKEDLIST_H

template<class T>
class LinkedList {
public:
    LinkedList();

    ~LinkedList();

    bool isEmpty();

    T readElem(Node pos);

    void writeElem(T elem, Node pos);

    bool isEnd(Node pos);

    Node getNext(Node pos);

    Node getPrev(Node pos);

    void insert();

    void remove(Node pos);

    // TODO: Operator =

    bool operator==(const LinkedList<T> &) const;

    // TODO: Operator !=
};


#endif //ASD_EXAM_STRUCTURES_LINKEDLIST_H
