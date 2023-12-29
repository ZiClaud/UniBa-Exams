#ifndef ALGORITMI_LAB_MYLIST_H
#define ALGORITMI_LAB_MYLIST_H

template<class T>
class MyList {
private:
    T elements[1024];
    int length = 1024;

    bool isPosValid(int pos);
    void cleanList();
public:
    MyList();

    ~MyList();

    bool isEmpty() const;

    bool isEnd(int pos) const;

    int getNext(int pos) const;

    int getPrevious(int pos) const;

    T read(int pos) const;

    void write(T elem, int pos);

    void insert(T elem, int pos);

    void remove(int pos);
};


#endif //ALGORITMI_LAB_MYLIST_H
