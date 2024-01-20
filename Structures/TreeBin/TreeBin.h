//
// Created by ziclaud on 15/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_TREEBIN_H
#define ASD_EXAM_STRUCTURES_TREEBIN_H

#include <stdexcept>
#include <iostream>

/// @brief Exceptions
struct NullNode : public std::invalid_argument {
    NullNode() : invalid_argument(
            "Parametro nodo nullo.") {};
};

struct FullSize : public std::invalid_argument {
    FullSize() : invalid_argument(
            "Dimensione massima raggiunta.") {};
};

struct RootExists : public std::domain_error {
    RootExists() : domain_error(
            "Radice giÃ  presente.") {};
};

struct EmptyTree : public std::domain_error {
    EmptyTree() : domain_error(
            "Albero vuoto.") {};
};

struct NodeExists : public std::domain_error {
    NodeExists() : domain_error(
            "Node giÃ  presente.") {};
};

/// @brief Interfaccia per un albero binario
template<class T, class N>
class _TreeBin {
    static const int NIL = -1;
public:
    // tipi
    typedef T value;
    typedef N Node;

    // operatori

    virtual void _create() = 0;

    virtual bool empty() const = 0;

    virtual Node root() const = 0;

    virtual Node parent(Node) const = 0;

    virtual Node sx(Node) const = 0;

    virtual Node dx(Node) const = 0;

    virtual bool sx_empty(Node) const = 0;

    virtual bool dx_empty(Node) const = 0;

    //virtual void costr(_TreeBin<T,N>);

    virtual void erase(Node) = 0;

    virtual T read(Node) const = 0;

    virtual void write(Node, value) = 0;

    virtual void ins_root(Node) = 0;

    virtual void ins_sx(Node) = 0;

    virtual void ins_dx(Node) = 0;

    // funzioni di servizio da implementare qui

    //virtual void previsit(Node);

    //virtual void invisita(Node);

    //virtual void postvisit(Node);


    virtual void print() const;

private:
    virtual void printSubTree(const Node) const;
};

template<class T, class N>
void _TreeBin<T, N>::print() const {
    if (!empty()) {
        printSubTree(root());
    } else {
        std::cout << "[]" << std::endl;
    }
    std::cout << std::endl;
}

template<class T, class N>
void _TreeBin<T, N>::printSubTree(const Node n) const {
    std::cout << "[" << n << ", ";
    if (!sx_empty(n)) {
        printSubTree(sx(n));
    } else {
        std::cout << "NIL";
    }
    std::cout << ", ";
    if (!dx_empty(n)) {
        printSubTree(dx(n));
    } else {
        std::cout << "NIL";
    }
    std::cout << " ]";
}

template<class T, class N>
std::ostream &operator<<(std::ostream &out, const _TreeBin<T, N> &t) {
    t.print();
    return out;
}


/// @brief Binary Tree
template<class T>
class TreeBin : public _TreeBin<T, int> {
    static const int NIL = -1;

public:

    typedef typename _TreeBin<T, int>::value value;
    typedef typename _TreeBin<T, int>::Node Nodo;

    struct _cella {
        Nodo genitore;
        Nodo sinistro;
        Nodo destro;
        value valore;
    };

    typedef struct _cella Cella;

    // costruttori e distruttori

    TreeBin();

    TreeBin(int);

    ~TreeBin();

    // operatori

    void _create();

    bool empty() const;

    Nodo root() const;

    Nodo parent(Nodo) const;

    Nodo sx(Nodo) const;

    Nodo dx(Nodo) const;

    bool sx_empty(Nodo) const;

    bool dx_empty(Nodo) const;

    //void costr(TreeBin<T>);

    void erase(Nodo);

    T read(Nodo) const;

    void write(Nodo, value);

    void ins_root(Nodo);

    void ins_sx(Nodo);

    void ins_dx(Nodo);

private:
    int MAXLUNG;
    Cella *spazio;
    int nNodi;
    Nodo inizio;
    Nodo libera;
};

template<class T>
TreeBin<T>::TreeBin() {
    MAXLUNG = 100;
    spazio = new Cella[MAXLUNG];
    _create();
}

template<class T>
TreeBin<T>::TreeBin(int nNodi): MAXLUNG(nNodi) {
    spazio = new Cella[nNodi];
    _create();
}


template<class T>
TreeBin<T>::~TreeBin() {
    erase(inizio);
    delete[] spazio;
}

template<class T>
void TreeBin<T>::_create() {
    inizio = NIL;
    for (int i = 0; i < MAXLUNG; i++) {
        spazio[i].sinistro = (i + 1) % MAXLUNG;
    }

    libera = 0;
    nNodi = 0;
}

template<class T>
bool TreeBin<T>::empty() const {
    return (nNodi == 0);
}

template<class T>
typename TreeBin<T>::Nodo TreeBin<T>::root() const {
    return (inizio);
}

template<class T>
typename TreeBin<T>::Nodo TreeBin<T>::parent(Nodo n) const {
    if (n != inizio) {
        return (spazio[n].genitore);
    } else {
        return (n);
    }
}

template<class T>
typename TreeBin<T>::Nodo TreeBin<T>::sx(Nodo n) const {
    if (!sx_empty(n)) {
        return (spazio[n].sinistro);
    } else {
        return (n);
    }
};

template<class T>
typename TreeBin<T>::Nodo TreeBin<T>::dx(Nodo n) const {
    if (!dx_empty(n)) {
        return (spazio[n].destro);
    } else {
        return (n);
    }
}

template<class T>
bool TreeBin<T>::sx_empty(TreeBin<T>::Nodo n) const {
    return (spazio[n].sinistro == NIL);
}

template<class T>
bool TreeBin<T>::dx_empty(TreeBin<T>::Nodo n) const {
    return (spazio[n].destro == NIL);
}

template<class T>
void TreeBin<T>::ins_root(TreeBin<T>::Nodo n) {
    if (inizio == NIL) {
        inizio = libera;
        libera = spazio[libera].sinistro;
        spazio[inizio].sinistro = NIL;
        spazio[inizio].destro = NIL;
        nNodi++;
    } else {
        throw RootExists();
    }
}


template<class T>
void TreeBin<T>::ins_sx(Nodo n) {
    if (inizio == NIL) {
        throw EmptyTree();
    } else if (n == NIL) {
        throw NullNode();
    } else if (spazio[n].sinistro != NIL) {
        throw NodeExists();
    } else if (nNodi >= MAXLUNG) {
        throw FullSize();
    }

    Nodo q = libera;
    libera = spazio[libera].sinistro;
    spazio[n].sinistro = q;
    spazio[q].sinistro = NIL;
    spazio[q].genitore = n;
    spazio[q].destro = NIL;
    nNodi++;
}

template<class T>
void TreeBin<T>::ins_dx(Nodo n) {
    if (inizio == NIL) {
        throw EmptyTree();
    } else if (n == NIL) {
        throw NullNode();
    } else if (spazio[n].destro != NIL) {
        throw NodeExists();
    }

    if (nNodi >= MAXLUNG) {
        throw FullSize();
    } else {
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
void TreeBin<T>::erase(Nodo n) {
    if (n != NIL) {
        if (!sx_empty(n)) {
            erase(spazio[n].sinistro);
        }
        if (!dx_empty(n)) {
            erase(spazio[n].destro);
        }
        if (n != inizio) {
            Nodo p = parent(n);
            if (spazio[p].sinistro == n) {
                spazio[p].sinistro = NIL;
            } else {
                spazio[p].destro = NIL;
            }
        } else {
            inizio = NIL;
        }
        nNodi--;
        spazio[n].sinistro = libera;
        libera = n;
    } else {
        throw NullNode();
    }
}

template<class T>
T TreeBin<T>::read(Nodo n) const {
    if (n != NIL) {
        return (spazio[n].valore);
    } else {
        throw NullNode();
    }
}

template<class T>
void TreeBin<T>::write(Nodo n, value a) {
    if (n != NIL) {
        spazio[n].valore = a;
    } else {
        throw NullNode();
    }
}

#endif //ASD_EXAM_STRUCTURES_TREEBIN_H
