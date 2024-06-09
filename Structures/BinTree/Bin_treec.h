//
// Created by ziclaud on 21/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_BIN_TREEC_H
#define ASD_EXAM_STRUCTURES_BIN_TREEC_H

#include "Bin_tree.h"
#include "exceptions.h"

template<class T>
class Bin_treec : public Bin_tree<T, int> {
    static const int NIL = -1;

public:

    typedef typename Bin_tree<T, int>::value_type value_type;
    typedef typename Bin_tree<T, int>::Nodo Nodo;

    struct _cella {
        Nodo genitore;
        Nodo sinistro;
        Nodo destro;
        value_type valore;
    };

    typedef struct _cella Cella;

    // costruttori e distruttori
    Bin_treec();

    Bin_treec(int);

    ~Bin_treec();

    // operatori
    void create();

    bool empty() const;

    Nodo root() const;

    Nodo parent(Nodo) const;

    Nodo sx(Nodo) const;

    Nodo dx(Nodo) const;

    bool sx_empty(Nodo) const;

    bool dx_empty(Nodo) const;

    //void costr(Bin_treec<T>);
    void erase(Nodo);

    T read(Nodo) const;

    void write(Nodo, value_type);

    void ins_root();

    void ins_sx(Nodo);

    void ins_dx(Nodo);

    void printBT(Nodo node);

private:
    int MAXLUNG;
    Cella *spazio;
    int nNodi;
    Nodo inizio;
    Nodo libera;

    void _printBT(const string &prefix, Nodo node, bool isLeft);
};

template<class T>
Bin_treec<T>::Bin_treec() {
    MAXLUNG = 100;
    spazio = new Cella[MAXLUNG];
    create();
}

template<class T>
Bin_treec<T>::Bin_treec(int nNodi) : MAXLUNG(nNodi) {
    spazio = new Cella[nNodi];
    create();
}


template<class T>
Bin_treec<T>::~Bin_treec() {
    erase(inizio);
    delete[] spazio;
}

template<class T>
void Bin_treec<T>::create() {
    inizio = NIL;
    for (int i = 0; i < MAXLUNG; i++) {
        spazio[i].sinistro = (i + 1) % MAXLUNG;
    }

    libera = 0;
    nNodi = 0;
}

template<class T>
bool Bin_treec<T>::empty() const {
    return (nNodi == 0);
}

template<class T>
typename Bin_treec<T>::Nodo Bin_treec<T>::root() const {
    return (inizio);
}

template<class T>
typename Bin_treec<T>::Nodo Bin_treec<T>::parent(Nodo n) const {
    if (n != inizio)
        return (spazio[n].genitore);
    else
        return (n);
}

template<class T>
typename Bin_treec<T>::Nodo Bin_treec<T>::sx(Nodo n) const {
    if (!sx_empty(n))
        return (spazio[n].sinistro);
    else
        return (n);
};

template<class T>
typename Bin_treec<T>::Nodo Bin_treec<T>::dx(Nodo n) const {
    if (!dx_empty(n))
        return (spazio[n].destro);
    else
        return (n);
}

template<class T>
bool Bin_treec<T>::sx_empty(Bin_treec<T>::Nodo n) const {
    return (spazio[n].sinistro == NIL);
}

template<class T>
bool Bin_treec<T>::dx_empty(Bin_treec<T>::Nodo n) const {
    return (spazio[n].destro == NIL);
}

template<class T>
void Bin_treec<T>::ins_root() {
    if (inizio == NIL) {
        inizio = libera;
        libera = spazio[libera].sinistro;
        spazio[inizio].sinistro = NIL;
        spazio[inizio].destro = NIL;
        nNodi++;
    } else
        throw RootExists();
}


template<class T>
void Bin_treec<T>::ins_sx(Nodo n) {
    if (inizio == NIL)
        throw EmptyTree();
    if (n == NIL)
        throw NullNode();
    if (spazio[n].sinistro != NIL)
        throw NodeExists();
    if (nNodi >= MAXLUNG)
        throw FullSize();
    else {
        Nodo q = libera;
        libera = spazio[libera].sinistro;
        spazio[n].sinistro = q;
        spazio[q].sinistro = NIL;
        spazio[q].genitore = n;
        spazio[q].destro = NIL;
        nNodi++;
    }
}

template<class T>
void Bin_treec<T>::ins_dx(Nodo n) {
    if (inizio == NIL)
        throw EmptyTree();
    if (n == NIL)
        throw NullNode();
    if (spazio[n].destro != NIL)
        throw NodeExists();
    if (nNodi >= MAXLUNG)
        throw FullSize();
    else {
        Nodo q = libera;
        libera = spazio[libera].sinistro;
        spazio[n].destro = q;
        spazio[q].genitore = n;
        spazio[q].sinistro = NIL;
        spazio[q].destro = NIL;
        nNodi++;
    }
}

template<class T>
void Bin_treec<T>::erase(Nodo n) {
    if (n != NIL) {
        if (!sx_empty(n))
            erase(spazio[n].sinistro);
        if (!dx_empty(n))
            erase(spazio[n].destro);
        if (n != inizio) {
            Nodo p = parent(n);
            if (spazio[p].sinistro == n)
                spazio[p].sinistro = NIL;
            else
                spazio[p].destro = NIL;
        } else
            inizio = NIL;
        nNodi--;
        spazio[n].sinistro = libera;
        libera = n;
    } else
        throw NullNode();
}

template<class T>
T Bin_treec<T>::read(Nodo n) const {
    if (n != NIL)
        return (spazio[n].valore);
    else
        throw NullNode();
}

template<class T>
void Bin_treec<T>::write(Nodo n, value_type a) {
    if (n != NIL)
        spazio[n].valore = a;
    else
        throw NullNode();
}

template<class T>
void Bin_treec<T>::_printBT(const string &prefix, Nodo node, bool isLeft) {
    if (node != NIL) {
        cout << prefix;

        if (node == inizio)
            cout << "└───";
        else
            cout << (isLeft ? "├sx─" : "└dx─");

        // print the value of the node
        cout << read(node) << endl;

        // enter the next tree level - left and right branch
        if (!sx_empty(node))
            _printBT(prefix + (isLeft ? "│   " : "    "), sx(node), true);
        if (!dx_empty(node))
            _printBT(prefix + (isLeft ? "│   " : "    "), dx(node), false);
    }
}

template<class T>
void Bin_treec<T>::printBT(Nodo node) {
    _printBT("", node, false);
}

template<class T>
ostream &operator<<(ostream &out, Bin_treec<T> &t) {
    t.printBT(t.root());
    return out;
}

#endif //ASD_EXAM_STRUCTURES_BIN_TREEC_H
