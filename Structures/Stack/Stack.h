//
// Created by ziclaud on 15/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_STACK_H
#define ASD_EXAM_STRUCTURES_STACK_H

#include <iostream>

using namespace std;

template<class T>
class Stack {
public:
    Stack();

    Stack(int);

    ~Stack();

    bool isEmpty() const;

    T read() const;

    void removeLast();

    void insert(T);

private:
    T *elements;
    int MAXLUNGH;
    int head = 0;
};


template<class T>
Stack<T>::Stack() {
    elements = new T[100]; // dimensione standard della pila
    MAXLUNGH = 100;
}

template<class T>
Stack<T>::Stack(int N) {
    elements = new T[N]; // dimensione N della pila
    MAXLUNGH = N;
}

template<class T>
Stack<T>::~Stack() {
    delete[] elements;
}

template<class T>
bool Stack<T>::isEmpty() const {
    return head == 0;
}

template<class T>
T Stack<T>::read() const {
    return elements[head - 1];
}

template<class T>
void Stack<T>::removeLast() {
    if (!isEmpty()) {
        head -= 1;
    } else {
        throw invalid_argument("No elem in stack");
    }
}

template<class T>
void Stack<T>::insert(T el) {
    if (head > MAXLUNGH) {
        throw invalid_argument("Max length reached");
    } else {
        elements[head] = el;
        head++;
    }
}

template<class T>
ostream &operator<<(ostream &os, Stack<T> &s) {
    Stack<T> *s1 = new Stack<T>();
    while (!(s.isEmpty())) {
        (*s1).insert(s.read());
        s.removeLast();
    }
    os << "[";
    for (int i = 0; !(*s1).isEmpty(); i++) {
        if (i != 0) {
            os << ", " << (*s1).read();
        } else {
            os << (*s1).read();
        }
        s.insert((*s1).read());
        (*s1).removeLast();
    }
    os << "]";
    return os;
}

#endif //ASD_EXAM_STRUCTURES_STACK_H
