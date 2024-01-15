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
private:
    Node<T>* head;
    Node<T>* tail;
public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Check if the linked list is empty
    bool isEmpty();

    // Read the element stored in a given node
    T readElem(Node<T> node);

    // Override the value stored in a given node
    void writeElem(T elem, Node<T> node);

    // Check if a given node is at the end of the list
    bool isEnd(Node<T> node);

    // Get the starting node of the list
    Node<T> getStart();

    // Get the ending node of the list
    Node<T> getEnd();

    // Get the next node in the list after a given node
    Node<T> getNext(Node<T> node);

    // Get the previous node in the list before a given node
    Node<T> getPrev(Node<T> node);

    // Insert a new element after a given node
    void insert(T elem, Node<T> node);

    // Remove a given node from the list
    void remove(Node<T> node);

    // Copy assignment operator
    LinkedList<T> &operator=(const LinkedList<T> &list);

    // Equality operator
    bool operator==(const LinkedList<T> &list) const;

    // Inequality operator
    bool operator!=(const LinkedList<T> &list) const;

    // Prints list
    void print();
};

#endif //ASD_EXAM_STRUCTURES_LINKEDLIST_H
