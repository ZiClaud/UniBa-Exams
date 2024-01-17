//
// Created by ziclaud on 15/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_QUEUE_H
#define ASD_EXAM_STRUCTURES_QUEUE_H

#include <iostream>

using namespace std;

template<class T>
class Queue {
public:
    Queue(int maxLen) {
        maxLenght = maxLen;
        elements = new T[maxLenght];
    }

    ~Queue() {
        delete[] elements;
    }

    bool isEmpty() {
        return (lung == 0);
    }

    T read() {
        if (!isEmpty()) {
            return (elements[testa]);
        } else {
            throw out_of_range("Queue is empty");
        }
    }

    void removeFirst() {
        if (!isEmpty()) {
            testa = (testa + 1) % maxLenght;
            lung--;
        } else {
            throw out_of_range("Queue is empty");
        }
    }

    void insert(T a) {
        if (lung != maxLenght) {
            elements[(testa + lung) % maxLenght] = a;
            lung++;
        } else {
            throw out_of_range("Queue is full");
        }
    }

private:
    T *elements;
    int testa = 0;
    int lung = 0;
    int maxLenght;
};

template<class T>
ostream &operator<<(ostream &os, Queue<T> &q) {
    Queue<T> *q1 = new Queue<T>(100);
    while (!(q.isEmpty())) {
        (*q1).insert(q.read());
        q.removeFirst();
    }
    os << "[";
    for (int i = 0; !(*q1).isEmpty(); i++) {
        if (i != 0) {
            os << ", " << (*q1).read();
        } else {
            os << (*q1).read();
        }
        q.insert((*q1).read());
        (*q1).removeFirst();
    }
    os << "]";
    return os;
}

#endif //ASD_EXAM_STRUCTURES_QUEUE_H
