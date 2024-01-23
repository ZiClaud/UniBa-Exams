/*
 * Dato un albero binario realizzare in C++ una funzione che calcoli il numero per un dato livello k.
 *
 * Prevedere una funzione main che contenga una procedura di inserimento autpmatico e successivamente
 * il test della funzione.
 */

#include "Structures/BinTree/Bin_treec.h"

int _getLeafInLevel(Bin_treec<int> &tree, typename Bin_treec<int>::Nodo &currNode, int level, int k) {
    level--;
//    cout << "Curr value: " << tree.read(currNode) << endl;
    typename Bin_treec<int>::Nodo sx;
    typename Bin_treec<int>::Nodo dx;

    if (level == 0) {
        if (tree.sx_empty(currNode) && tree.dx_empty(currNode)) {
            k++;
//            cout << "--- Leaf found: " << tree.read(currNode) << " ---" << endl;
            return k;
        }
    }

//    cout << "!tree.sx_empty(currNode)" << !tree.sx_empty(currNode) << endl;
    if (!tree.sx_empty(currNode)) {
        sx = tree.sx(currNode);
        k = _getLeafInLevel(tree, sx, level, k);
    }
//    cout << "!tree.dx_empty(currNode)" << !tree.dx_empty(currNode) << endl;
    if (!tree.dx_empty(currNode)) {
        dx = tree.dx(currNode);
        k = _getLeafInLevel(tree, dx, level, k);
    }

    return k;
}

int getLeafInLevel(Bin_treec<int> &tree, int level) {
    typename Bin_treec<int>::Nodo curr = tree.root();
    typename Bin_treec<int>::Nodo sx;
    typename Bin_treec<int>::Nodo dx;
    int k = 0;

    if (level == 0) {
        if (tree.sx_empty(curr) && tree.dx_empty(curr)) {
            k++;
        }
        return k;
    }


    if (!tree.sx_empty(curr)) {
        sx = tree.sx(tree.root());
        k = _getLeafInLevel(tree, sx, level, k);
    }
    if (!tree.dx_empty(curr)) {
        dx = tree.dx(tree.root());
        k = _getLeafInLevel(tree, dx, level, k);
    }

    return k;
}

int main() {
    cout << "Binary tree:" << endl;
    Bin_treec<int> tree;
    Bin_treec<int> tree2;
    Bin_treec<int> tree3;
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

    int lvl1 = 0;
    cout << "N. of Leafs in level " << lvl1 << ": " << getLeafInLevel(tree, lvl1) << endl;
    lvl1 = 1;
    cout << "N. of Leafs in level " << lvl1 << ": " << getLeafInLevel(tree, lvl1) << endl;
    lvl1 = 2;
    cout << "N. of Leafs in level " << lvl1 << ": " << getLeafInLevel(tree, lvl1) << endl;
    lvl1 = 3;
    cout << "N. of Leafs in level " << lvl1 << ": " << getLeafInLevel(tree, lvl1) << endl;
    lvl1 = 4;
    cout << "N. of Leafs in level " << lvl1 << ": " << getLeafInLevel(tree, lvl1) << endl << endl << endl;

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

    int lvl2 = 0;
    cout << "N. of Leafs in level " << lvl2 << ": " << getLeafInLevel(tree2, lvl2) << endl;
    lvl2 = 1;
    cout << "N. of Leafs in level " << lvl2 << ": " << getLeafInLevel(tree2, lvl2) << endl;
    lvl2 = 2;
    cout << "N. of Leafs in level " << lvl2 << ": " << getLeafInLevel(tree2, lvl2) << endl;
    lvl2 = 3;
    cout << "N. of Leafs in level " << lvl2 << ": " << getLeafInLevel(tree2, lvl2) << endl;
    lvl2 = 4;
    cout << "N. of Leafs in level " << lvl2 << ": " << getLeafInLevel(tree2, lvl2) << endl << endl << endl;

    tree3.ins_root();
    tree3.write(tree.root(), 15);

    cout << tree3 << endl;

    int lvl3 = 0;
    cout << "N. of Leafs in level " << lvl3 << ": " << getLeafInLevel(tree3, lvl3) << endl;
    lvl3 = 1;
    cout << "N. of Leafs in level " << lvl3 << ": " << getLeafInLevel(tree3, lvl3) << endl;
    lvl3 = 2;
    cout << "N. of Leafs in level " << lvl3 << ": " << getLeafInLevel(tree3, lvl3) << endl;
    lvl3 = 3;
    cout << "N. of Leafs in level " << lvl3 << ": " << getLeafInLevel(tree3, lvl3) << endl;
    lvl3 = 4;
    cout << "N. of Leafs in level " << lvl3 << ": " << getLeafInLevel(tree3, lvl3) << endl;


    return 0;
}