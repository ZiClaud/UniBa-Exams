/*
 * Dato un albero binario, implementare un metodo per verificare che sia una sum-tree.
 * In un sum-tree il valore di ogni nodo non foglia (nodo interno) è uguale alla somma
 * di tutti gli elementi nei due sotto-alberi sinistro e destro.
 *
 * Prevedere una funzione main che contenga una procedura di inserimento autpmatico e successivamente
 * il test del motodo implementato.
 */

#include "Structures/BinTree/Bin_treec.h"

bool _isSumTree(Bin_treec<int> &tree, typename Bin_treec<int>::Nodo &currNode, bool ris) {
    if (!ris) {
        return false;
    }

    typename Bin_treec<int>::Nodo sx;
    typename Bin_treec<int>::Nodo dx;

    if (!tree.sx_empty(currNode) && !tree.dx_empty(currNode)) {
        sx = tree.sx(tree.root());
        dx = tree.dx(tree.root());
        if (tree.read(sx) + tree.read(dx) != tree.read(tree.root())) {
            return false;
        }
    } else {
        if (tree.sx_empty(currNode) && tree.dx_empty(currNode)) {
            // It's a leaf
            return true;
        } else if (tree.sx_empty(currNode) && !tree.dx_empty(currNode)) {
            // Sx is null
            if (tree.read(currNode) != tree.read(tree.dx(currNode))) {
                return false;
            }
        } else if (!tree.sx_empty(currNode) && tree.dx_empty(currNode)) {
            // Dx is null
            if (tree.read(currNode) != tree.read(tree.sx(currNode))) {
                return false;
            }
        }
    }

    if (!tree.sx_empty(currNode)) {
        sx = tree.sx(currNode);
        ris = _isSumTree(tree, sx, ris);
    }
    if (!tree.dx_empty(currNode)) {
        dx = tree.dx(currNode);
        ris = _isSumTree(tree, dx, ris);
    }

    return ris;
}

bool isSumTree(Bin_treec<int> &tree) {
    typename Bin_treec<int>::Nodo curr = tree.root();
    typename Bin_treec<int>::Nodo sx;
    typename Bin_treec<int>::Nodo dx;
    bool ris = true;

    if (!tree.sx_empty(curr) && !tree.dx_empty(curr)) {
        sx = tree.sx(tree.root());
        dx = tree.dx(tree.root());
        if (tree.read(sx) + tree.read(dx) != tree.read(tree.root())) {
            return false;
        }
    } else {
        if (tree.sx_empty(curr) && tree.dx_empty(curr)) {
            // It's a leaf
            return true;
        } else if (tree.sx_empty(curr) && !tree.dx_empty(curr)) {
            // Sx is null
            if (tree.read(curr) != tree.read(tree.dx(curr))) {
                return false;
            }
        } else if (!tree.sx_empty(curr) && tree.dx_empty(curr)) {
            // Dx is null
            if (tree.read(curr) != tree.read(tree.sx(curr))) {
                return false;
            }
        }
    }


    if (!tree.sx_empty(curr)) {
        sx = tree.sx(tree.root());
        ris = _isSumTree(tree, sx, true);
    }
    if (!tree.dx_empty(curr)) {
        dx = tree.dx(tree.root());
        ris = _isSumTree(tree, dx, true);
    }

    return ris;
}

int main() {

    cout << "Binary tree:" << endl;
    Bin_treec<int> tree;
    Bin_treec<int> tree2;
    typename Bin_treec<int>::Nodo n1 = 0;
    typename Bin_treec<int>::Nodo n2 = 0;

    tree.ins_root();
    tree.write(tree.root(), 1);
    n1 = tree.root();
    tree.ins_sx(n1);
    tree.ins_dx(n1);
    tree.write(tree.sx(n1), 2);
    n1 = tree.dx(n1);
    tree.write(n1, 3);
    tree.ins_dx(n1);
    tree.write(tree.dx(n1), 4);
    cout << tree << endl;

    cout << "Is sum tree: " << isSumTree(tree) << endl;

    typename Bin_treec<int>::Nodo l1 = 0, l1r1 = 0, l1l1 = 0, r1 = 0, r1r1 = 0, r1l1 = 0;
    tree2.ins_root();
    tree2.write(tree2.root(), 10);

    l1 = tree2.root();
    tree2.ins_sx(l1);
    tree2.write(tree2.sx(l1), 4);

    r1 = tree2.root();
    tree2.ins_dx(r1);
    tree2.write(tree2.dx(r1), 6);

    l1r1 = tree2.sx(l1);
    tree2.ins_dx(l1r1);
    tree2.write(tree2.dx(l1r1), 1);

    l1l1 = tree2.sx(l1);
    tree2.ins_sx(l1l1);
    tree2.write(tree2.sx(l1l1), 3);

    r1r1 = tree2.dx(r1);
    tree2.ins_dx(r1r1);
    tree2.write(tree2.dx(r1r1), 2);

    r1l1 = tree2.dx(r1);
    tree2.ins_sx(r1l1);
    tree2.write(tree2.sx(r1l1), 4);

    cout << tree2 << endl;

    cout << "Is sum tree: " << isSumTree(tree2) << endl;

    return 0;
}