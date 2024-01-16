//
// Created by ziclaud on 15/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_LISTVECTOR_H
#define ASD_EXAM_STRUCTURES_LISTVECTOR_H

#include "../LinkedList/LinearList.h"

// classe Lista
template<class T>
class ListVector : public LinearList<T, int> {
public:
    typedef typename LinearList<T, int>::value_type value_type;
    typedef typename LinearList<T, int>::position position;

    // costruttori
    ListVector();

    ListVector(int);

    // costruttore per copia
    ListVector(const ListVector<T> &);

    //distruttore
    ~ListVector();

    // operatori
    bool empty() const;

    value_type read(position) const;

    void write(const value_type &, position);

    position begin() const;

    bool end(position) const;

    position next(position) const;

    position previous(position) const;

    void insert(const value_type &, position);

    void erase(position);

    // sovraccarico di operatori
    ListVector<T> &operator=(const ListVector<T> &); // the assignment operator
    bool operator==(const ListVector<T> &) const; // tests two list for equality
private:
    void change_dimension_(T *&, int, int);

    void _create();

    value_type *elements_;
    int length_ = 0; // the length of the list
    int array_dimension_; // array's dimension
};

// costruttore
template<class T>
ListVector<T>::ListVector() {
    array_dimension_ = 10;
    this->_create();
}

// costruttore
template<class T>
ListVector<T>::ListVector(int dim) {
    array_dimension_ = dim;
    this->_create();
}

/* Il costruttore per copia effettua una copia o clone di un oggetto.
 * Questo costruttore viene invocato, per esempio, quando un oggetto viene passato
 * per valore ad una funzione o quando una funzione restituisce un oggetto.
 */
template<class T>
ListVector<T>::ListVector(const ListVector<T> &Lista) {
    this->array_dimension_ = Lista.array_dimension_;
    this->length_ = Lista.length_;
    this->elements_ = new T[array_dimension_];
    for (int i = 0; i < Lista.array_dimension_; i++)
        this->elements_[i] = Lista.elements_[i];
}

// distruttore
template<class T>
ListVector<T>::~ListVector() {
    delete elements_;
}

// operatori
template<class T>
void ListVector<T>::_create() {
    elements_ = new T[array_dimension_];
}

template<class T>
bool ListVector<T>::empty() const {
    return (length_ == 0);
}

template<class T>
typename ListVector<T>::position ListVector<T>::begin() const {
    return (1); // e quindi pos(1)=pos(n+1) se la lista e' vuota (n=0)
}

template<class T>
typename ListVector<T>::position ListVector<T>::next(position p) const {
    if ((0 < p) && (p < length_ + 1)) // precondizione
        return (p + 1);
    else
        return (p);
}

template<class T>
typename ListVector<T>::position ListVector<T>::previous(position p) const {
    if ((1 < p) && (p < length_ + 1)) // precondizione
        return (p - 1);
    else
        return (p);
}

template<class T>
bool ListVector<T>::end(position p) const {
    if ((0 < p) && (p <= length_ + 1)) // precondizione
        return (p == length_ + 1);
    else
        return (false);
}

template<class T>
typename ListVector<T>::value_type ListVector<T>::read(position p) const {
    if ((0 < p) && (p < length_ + 1)) // precondizione
        return (elements_[p - 1]);
}

template<class T>
void ListVector<T>::write(const value_type &a, position p) {
    if ((0 < p) && (p < length_ + 1)) // precondizione
        elements_[p - 1] = a;
}

template<class T>
void ListVector<T>::insert(const value_type &a, position p) {
    if (length_ == array_dimension_) {
        change_dimension_(elements_, array_dimension_, array_dimension_ * 2);
        array_dimension_ = array_dimension_ * 2;
    }
    if ((0 < p) && (p <= length_ + 1)) { // precondizione
        for (int i = length_; i >= p; i--)
            elements_[i] = elements_[i - 1];
        elements_[p - 1] = a;
        length_++;
    }
}

template<class T>
void ListVector<T>::erase(position p) {
    if ((0 < p) && (p < length_ + 1)) // precondizione
        if (!empty()) {
            for (int i = p - 1; i < (length_ - 1); i++)
                elements_[i] = elements_[i + 1];
            length_--;
        }
}

template<class T>
void ListVector<T>::change_dimension_(T *&a, int vecchiaDim, int nuovaDim) {

    T *temp = new T[nuovaDim];
    int number;
    if (vecchiaDim < nuovaDim)
        number = vecchiaDim;
    else
        number = nuovaDim;
    for (int i = 0; i < number; i++)
        temp[i] = a[i];
    delete[] a;
    a = temp;
}

/* operatore di assegnamento */
template<class T>
ListVector<T> &ListVector<T>::operator=(const ListVector<T> &l) {
    if (this != &l) {   // attenzione agli autoassegnamenti: l = l
        this->array_dimension_ = l.array_dimension_;
        this->length_ = l.length_;
        delete this->elements_;
        this->elements_ = new T[array_dimension_];
        for (int i = 0; i < l.array_dimension_; i++)
            this->elements_[i] = l.elements_[i];
    }
    return *this;
}

/* operatore di test di uguaglianza */
template<class T>
bool ListVector<T>::operator==(const ListVector<T> &l) const {
    if (l.length_ != this->length_)
        return false;
    for (int i = 0; i < this->array_dimension_; i++)
        if (this->elements_[i] != l.elements_[i])
            return false;
    return true;
}

#endif //ASD_EXAM_STRUCTURES_LISTVECTOR_H
