//
// Created by ziclaud on 17/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_HASHTABLE_H
#define ASD_EXAM_STRUCTURES_HASHTABLE_H

#include "Dictionary.h"

#include <string>
#include <stdexcept>

using std::string;

template<class T>
class Hash {
public:
    size_t operator()(const T the_key) const;
};


/* a specialization with type string */
template<>
class Hash<string> {
public:
    size_t operator()(const string the_key) const {
        unsigned long hash_value = 0;
        int length = (int) the_key.length();
        for (int i = 0; i < length; i++)
            hash_value = 5 * hash_value + the_key.at(i);
        return size_t(hash_value);
    }
};

/* HashTable class with linear probing */

template<class K, class E>
struct MyPair;

template<class K, class E>
class HashTable : public Dictionary<K, E> {
public:
    HashTable(int);        // the constructor

    bool empty() const {
        return (dsize == 0);
    };

    int size() const {
        return dsize;
    };

    void erase(const K &k);

    void modify(const K &k, const E &e);

    int search(const K &) const;

    MyPair<K, E> *find(const K &) const;

    void insert(MyPair<K, E> &);

private:
    MyPair<K, E> **table;   // the Hash table
    Hash<K> hashm;  // maps type K to nonnegative integer
    int dsize;  // number of pairs in dictionary
    int divisor;    // Hash function divisor
};

template<class K, class E>
HashTable<K, E>::HashTable(int the_divisor) {
    divisor = the_divisor;
    dsize = 0;

    table = new MyPair<K, E> *[divisor];
    for (int i = 0; i < divisor; i++)
        table[i] = NULL;
}

/* This method returns a bucket b in the table that satisfies exactly one of the following:
 * 1) table[b] points to a pair whose key is the_key
 * 2) no pair in the table has the key the_key, table[b] is NULL
 * 3) no pair in the table has the the_key, table[b] has a key other than the_key, and the
 *   table is full
 */

template<class K, class E>
int HashTable<K, E>::search(const K &the_key) const {
    int i = (int) hashm(the_key) % divisor;   // the home bucket
    int j = i;
    do {
        if (table[j] == NULL || table[j]->key == the_key)
            return j;
        j = (j + 1) % divisor;                    // the next bucket
    } while (j != i);

    return j;                                 // the table is full
}

/* The method HashTable<K,E>::find */

template<class K, class E>
MyPair<K, E> *HashTable<K, E>::find(const K &the_key) const {
    // search the table
    int b = search(the_key);
    // see if a match was found at table[b]
    if (table[b] == NULL || table[b]->key != the_key)
        return NULL;    // no match
    return table[b];  // matching pair
}

/* = INSERTING =
 *
 * It begins by invoking the method search. If the returned bucket b is empty, then there is no
 * pair in the table with key the_pair.key and the pair the_pair may be inserted into this
 * bucket. If the returned bucket is not empty, then it either contains a pair with key the_pair.key
 * or the table is full. In the former case we change the element component of the pair stored
 * in the bucket to the_pair.element; in the latter, we throw an exception
 */

template<class K, class E>
void HashTable<K, E>::insert(MyPair<K, E> &the_pair) {
    // search the table for a matching element
    int b = search(the_pair.key);
    // chack if matching element found
    if (table[b] == NULL) {
        // no matching element and table not full
        table[b] = new MyPair<K, E>(the_pair);
        dsize++;
    } else {
        // check id duplicate or table full
        if (table[b]->key == the_pair.key)
            // duplicate, change table[b]->element
            table[b]->element = the_pair.element;
        else {
            throw invalid_argument("Hash table is full");
        }
    }
}

template<class K, class E>
void HashTable<K, E>::erase(const K &k) {
    // TODO
}

template<class K, class E>
void HashTable<K, E>::modify(const K &k, const E &e) {
    // TODO
}

#endif //ASD_EXAM_STRUCTURES_HASHTABLE_H
