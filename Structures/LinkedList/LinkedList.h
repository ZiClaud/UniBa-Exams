//
// Created by ziclaud on 15/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_LINKEDLIST_H
#define ASD_EXAM_STRUCTURES_LINKEDLIST_H

#include <stdexcept>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T> *next;
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
    Node<T> getHead();

    // Get the ending node of the list
    Node<T> getTail();

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

template<class T>
LinkedList<T>::LinkedList() {
    head = new Node<T>();
    tail = head;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T> *curr = head;
    Node<T> *next;
    while (tail != nullptr) {
        next = head->next;
        delete curr;
        curr = next;
    }
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return (head->next == tail && head->data == nullptr); // TODO: Check if ok
}

template<class T>
T LinkedList<T>::readElem(Node<T> node) {
    return node.data;
}

template<class T>
void LinkedList<T>::writeElem(T elem, Node<T> node) {
    if (!this->contains(node)) {
        throw invalid_argument("Node not in list");
    }
    node.data = elem;
}

template<class T>
bool LinkedList<T>::isEnd(Node<T> node) {
    return (node == getTail());
}

template<class T>
Node<T> LinkedList<T>::getHead() {
    return head;
}

template<class T>
Node<T> LinkedList<T>::getTail() {
    return tail;
}

template<class T>
Node<T> LinkedList<T>::getNext(Node<T> node) {
    return node.next;
}


#endif //ASD_EXAM_STRUCTURES_LINKEDLIST_H
