#include "matrice.h"

int main() {
    cout << "Hello, World!" << endl;

    Matrice A(2, 3);
    cout << "A1:" << endl;
    A.printMatrix();

    A.scrivimatrice(0, 0, 1);
    A.scrivimatrice(1, 0, 2);
    A.scrivimatrice(0, 1, 3);
    A.scrivimatrice(1, 1, 4);
    A.scrivimatrice(0, 2, 5);
    A.scrivimatrice(1, 2, 6);

    cout << "A2:" << endl;
    A.printMatrix();

    Matrice B = A.trasposta();

    cout << "B1:" << endl;
    B.printMatrix();

    B.prodottoScalare(2);

    cout << "B2:" << endl;
    B.printMatrix();

    Matrice C1 = A.prodotto(B);
    cout << "C1:" << endl;
    C1.printMatrix();

    Matrice C2 = B.prodotto(A);
    cout << "C2:" << endl;
    C2.printMatrix();

    return 0;
}
