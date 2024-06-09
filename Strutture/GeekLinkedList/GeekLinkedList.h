//
// Created by ziclaud on 09/01/24.
//

#ifndef ALGORITMI_LAB_GEEKLINKEDLIST_H
#define ALGORITMI_LAB_GEEKLINKEDLIST_H

// C++ program for the above approach
#include <iostream>

using namespace std;

// Node class to represent
// a node of the linked list.
template <class T>
class Node {
public:
    T data;
    Node *next;

    // Default constructor
    Node() {
        data = T();
        next = nullptr;
    }

    // Parameterised Constructor
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Linked list class to
// implement a linked list.
template <class T>
class Linkedlist {
    Node<T> *head;

public:
    // Default constructor
    Linkedlist() { head = nullptr; }

    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int);

    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // node at given position
    void deleteNode(int);
};

// Function to delete the
// node at given position
template <class T>
void Linkedlist<T>::deleteNode(int nodeOffset) {
    Node<T> *temp1 = head;
    Node<T> *temp2 = nullptr;
    int ListLen = 0;

    if (head == nullptr) {
        cout << "List empty." << endl;
        return;
    }

    // Find length of the linked-list.
    while (temp1 != nullptr) {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be
    // deleted is greater than the length
    // of the linked list.
    if (ListLen < nodeOffset) {
        cout << "Index out of range" << endl;
        return;
    }

    // Declare temp1
    temp1 = head;

    // Deleting the head.
    if (nodeOffset == 1) {

        // Update head
        head = head->next;
        delete temp1;
        return;
    }

    // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 1) {

        // Update temp2
        temp2 = temp1;

        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;

    // Delete the node
    delete temp1;
}

// Function to insert a new node.
template <class T>
void Linkedlist<T>::insertNode(int data) {
    // Create the new Node.
    Node<T> *newNode = new Node(data);

    // Assign to head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse till end of list
    Node<T> *temp = head;
    while (temp->next != nullptr) {

        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newNode;
}

// Function to print the
// nodes of the linked list.
template <class T>
void Linkedlist<T>::printList() { // TODO: Copiare vecchia print
    Node<T> *temp = head;

    // Check for empty list.
    if (head == nullptr) {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//TODO: Overloading di =, ==, e !=

//TODO: Also use what the prof wants

#endif //ALGORITMI_LAB_GEEKLINKEDLIST_H
