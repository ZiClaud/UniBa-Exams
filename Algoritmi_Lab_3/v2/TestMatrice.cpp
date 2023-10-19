#include <iostream>
#include "matrice.h"

using namespace std;

void printMatrix(Matrice &m){
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getColomns(); ++j) {
            cout << m.leggimatrice(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cout << "Hello, World!" << endl;

    Matrice A(2, 3);
    printMatrix(A);

    A.scrivimatrice(0, 0, 1);
    A.scrivimatrice(1, 0, 2);
    A.scrivimatrice(0, 1, 3);
    A.scrivimatrice(1, 1, 4);
    A.scrivimatrice(0, 2, 5);
    A.scrivimatrice(1, 2, 6);
    printMatrix(A);

    Matrice B = A.trasposta();
    printMatrix(B);

    B.prodottoScalare(2);
    printMatrix(B);

    return 0;
}
