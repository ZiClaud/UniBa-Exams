#ifndef ALGORITMI_LAB_LIST_OPERATIONS_H
#define ALGORITMI_LAB_LIST_OPERATIONS_H

#include <list>

using namespace std;

template<class T>
class List_Operations {
public:
    int lunghezza(list<T>);

    void inverti(list<T> &);

    bool palindoma(list<T>);
};


#endif //ALGORITMI_LAB_LIST_OPERATIONS_H
