#ifndef ALGORITMI_LAB_MYLINKEDLIST_H
#define ALGORITMI_LAB_MYLINKEDLIST_H

template<class T>
class MyLinkedList {
private:
    MyLinkedList<T> *prev;
    MyLinkedList<T> *next;
    T val;
public:
    explicit MyLinkedList(T value) {
        val = value;
    }

    MyLinkedList<T> getNext();

    MyLinkedList<T> getPrev();

    void addNext(MyLinkedList<T>);

    void addPrev(MyLinkedList<T>);

    void removeNext();

    void removePrev();

    void print();
};

#endif //ALGORITMI_LAB_MYLINKEDLIST_H
