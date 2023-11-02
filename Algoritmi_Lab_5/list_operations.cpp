#include "list_operations.h"

//template<class T>
int lunghezza(list<int> l) {
    return l.size();
}

//template<class T>
void inverti(list<int> &l) {
    l.reverse();
}

// TODO: Change this -> Do it in another way, without 'auto'
//template<class T>
bool palindoma(list<int> l) {
    auto it = l.begin();
    auto rit = l.rbegin();

    for (int i = 0; i < lunghezza(l) / 2; i++) {
        if (*it != *rit) {
            return false;
        }
        it++;
        rit++;
    }

    return true;
}
