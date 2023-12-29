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

    bool isEnd(int) const;

    int getNext(int) const;

    int getPrevious(int) const;

    T read(int) const;

    void insert(T, int);

    void remove(int);
};


#endif //ALGORITMI_LAB_MYLIST_H
