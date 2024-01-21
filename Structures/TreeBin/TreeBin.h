//
// Created by ziclaud on 15/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_TREEBIN_H
#define ASD_EXAM_STRUCTURES_TREEBIN_H

#include <stdexcept>
#include <iostream>

/// @brief Exceptions
struct NullNode : public std::invalid_argument {
    NullNode() : invalid_argument("Node is null") {};
};

struct FullSize : public std::invalid_argument {
    FullSize() : invalid_argument("Full size reached") {};
};

struct RootExists : public std::domain_error {
    RootExists() : domain_error("Root exists") {};
};

struct EmptyTree : public std::domain_error {
    EmptyTree() : domain_error("Tree is isEmpty") {};
};

struct NodeExists : public std::domain_error {
    NodeExists() : domain_error("Node already exists") {};
};

/// @brief Binary Tree Interface
template<class T, class N>
class _TreeBin {
    static const int NIL = -1;
public:
    // tipi
    typedef T TT;
    typedef N TN;

    // operatori
    virtual void _create() = 0;

    virtual bool isEmpty() const = 0;

    virtual N getRootNode() const = 0;

    virtual N getParentNode(N) const = 0;

    virtual N getSxNode(N) const = 0;

    virtual N getDxNode(N) const = 0;

    virtual bool isSxEmpty(N) const = 0;

    virtual bool isDxEmpty(N) const = 0;

    //virtual void costr(_TreeBin<T,N>);

    virtual void erase(N) = 0;

    virtual T read(N) const = 0;

    virtual void write(N, T) = 0;

    virtual void insRoot(T) = 0;

    virtual void insSx(N) = 0;

    virtual void insDx(N) = 0;

    // funzioni di servizio da implementare qui

    //virtual void previsit(Node);

    //virtual void invisita(Node);

    //virtual void postvisit(Node);

    virtual void print() const;

private:
    virtual void printSubTree(const N) const;
};

template<class T, class N>
void _TreeBin<T, N>::print() const {
    if (!isEmpty()) {
        printSubTree(getRootNode());
    } else {
        std::cout << "[]" << std::endl;
    }
    std::cout << std::endl;
}

template<class T, class N>
void _TreeBin<T, N>::printSubTree(const N n) const {
    std::cout << "[" << n << ", ";
    if (!isSxEmpty(n)) {
        printSubTree(getSxNode(n));
    } else {
        std::cout << "NIL";
    }
    std::cout << ", ";
    if (!isDxEmpty(n)) {
        printSubTree(getDxNode(n));
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
    typedef typename _TreeBin<T, int>::TT TT;
    typedef typename _TreeBin<T, int>::TN TN;

    struct _cella {
        TN parent;
        TN left;
        TN right;
        TT val;
    };

    typedef struct _cella Cella;

    // costruttori e distruttori
    TreeBin();

    TreeBin(int);

    ~TreeBin();

    // operatori
    void _create();

    bool isEmpty() const;

    TN getRootNode() const;

    TN getParentNode(TN) const;

    TN getSxNode(TN) const;

    TN getDxNode(TN) const;

    bool isSxEmpty(TN) const;

    bool isDxEmpty(TN) const;

    //void costr(TreeBin<T>);

    void erase(TN);

    T read(TN) const;

    void write(TN, TT);

    void insRoot(TT);

    void insSx(TN);

    void insDx(TN);

private:
    int MAXLENGTH;
    Cella *space;
    int num_nodes;
    TN start;
    TN free;
};

/// Creates a tree with a set number of nodes set to 100
template<class T>
TreeBin<T>::TreeBin() {
    MAXLENGTH = 100;
    space = new Cella[MAXLENGTH];
    _create();
}

/// Creates a tree with a set number of nodes
template<class T>
TreeBin<T>::TreeBin(int num_nodes): MAXLENGTH(num_nodes) {
    space = new Cella[num_nodes];
    _create();
}

template<class T>
TreeBin<T>::~TreeBin() {
    erase(start);
    delete[] space;
}

template<class T>
void TreeBin<T>::_create() {
    start = NIL;
    for (int i = 0; i < MAXLENGTH; i++) {
        space[i].left = (i + 1) % MAXLENGTH;
    }

    free = 0;
    num_nodes = 0;
}

template<class T>
bool TreeBin<T>::isEmpty() const {
    return (num_nodes == 0);
}

template<class T>
typename TreeBin<T>::TN TreeBin<T>::getRootNode() const {
    return (start);
}

template<class T>
typename TreeBin<T>::TN TreeBin<T>::getParentNode(TN n) const {
    if (n != start) {
        return (space[n].parent);
    } else {
        return (n);
    }
}

template<class T>
typename TreeBin<T>::TN TreeBin<T>::getSxNode(TN n) const {
    if (!isSxEmpty(n)) {
        return (space[n].left);
    } else {
        return (n);
    }
};

template<class T>
typename TreeBin<T>::TN TreeBin<T>::getDxNode(TN n) const {
    if (!isDxEmpty(n)) {
        return (space[n].right);
    } else {
        return (n);
    }
}

template<class T>
bool TreeBin<T>::isSxEmpty(TN n) const {
    return (space[n].left == NIL);
}

template<class T>
bool TreeBin<T>::isDxEmpty(TN n) const {
    return (space[n].right == NIL);
}

template<class T>
void TreeBin<T>::insRoot(TT val) {
    if (start == NIL) {
        start = free;
        free = space[free].left;
        space[start].left = NIL;
        space[start].right = NIL;
        space[start].val = val;
        num_nodes++;
    } else {
        throw RootExists();
    }
}

template<class T>
void TreeBin<T>::insSx(TN n) {
    if (start == NIL) {
        throw EmptyTree();
    } else if (n == NIL) {
        throw NullNode();
    } else if (space[n].left != NIL) {
        throw NodeExists();
    } else if (num_nodes >= MAXLENGTH) {
        throw FullSize();
    }

    TN q = free;
    free = space[free].left;
    space[n].left = q;
    space[q].left = NIL;
    space[q].parent = n;
    space[q].right = NIL;
    num_nodes++;
}

template<class T>
void TreeBin<T>::insDx(TN n) {
    if (start == NIL) {
        throw EmptyTree();
    } else if (n == NIL) {
        throw NullNode();
    } else if (space[n].right != NIL) {
        throw NodeExists();
    }

    if (num_nodes >= MAXLENGTH) {
        throw FullSize();
    } else {
        TN q = free;
        free = space[free].left;
        space[n].right = q;
        space[q].parent = n;
        space[q].left = NIL;
        space[q].right = NIL;
        num_nodes++;
    }
}

template<class T>
void TreeBin<T>::erase(TN n) {
    if (n != NIL) {
        if (!isSxEmpty(n)) {
            erase(space[n].left);
        }
        if (!isDxEmpty(n)) {
            erase(space[n].right);
        }
        if (n != start) {
            TN p = getParentNode(n);
            if (space[p].left == n) {
                space[p].left = NIL;
            } else {
                space[p].right = NIL;
            }
        } else {
            start = NIL;
        }
        num_nodes--;
        space[n].left = free;
        free = n;
    } else {
        throw NullNode();
    }
}

template<class T>
T TreeBin<T>::read(TN n) const {
    if (n != NIL) {
        return (space[n].val);
    } else {
        throw NullNode();
    }
}

template<class T>
void TreeBin<T>::write(TN n, TT val) {
    if (n != NIL) {
        space[n].val = val;
    } else {
        throw NullNode();
    }
}

#endif //ASD_EXAM_STRUCTURES_TREEBIN_H
