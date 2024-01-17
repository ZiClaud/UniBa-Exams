//
// Created by ziclaud on 15/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_DICTIONARY_H
#define ASD_EXAM_STRUCTURES_DICTIONARY_H

using namespace std;

template<class K, class E>
struct MyPair {
    // data member
    K first;
    E second;

    // methods
    MyPair() {}

    MyPair(K first, E second) {
        first = first;
        second = second;
    }

    MyPair(MyPair<K, E> &the_pair) {
        first = the_pair.first;
        second = the_pair.second;
    }
};


template<class K, class E>
class Dictionary {
public:
    virtual ~Dictionary() {}

    // create an empty Dictionary
    virtual bool empty() const = 0;

    // return true iff the Dictionary is empty
    virtual int size() const = 0;

    // return the number of pairs in the Dictionary
    virtual MyPair<K, E> *find(const K &k) const = 0;

    // return the pair with key k
    virtual void insert(MyPair<K, E> &p) = 0;

    // insert the pair p into the Dictionary
    virtual void erase(const K &k) = 0;

    // delete the pair with key k
    virtual void modify(const K &k, const E &e) = 0;
    // modify the value of the pair with key k to e
};

#endif //ASD_EXAM_STRUCTURES_DICTIONARY_H
