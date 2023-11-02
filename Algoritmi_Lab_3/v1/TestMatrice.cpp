#include <iostream>
#include "matrice.h"

using namespace std;


int mainMatriceAlg3v1() {
    cout << "Hello, World!" << endl;

    Matrice A(2, 3);
    cout << A.leggimatrice(1, 1) << endl;

    A.scrivimatrice(0, 0, 1);
    A.scrivimatrice(0, 1, 2);
    A.scrivimatrice(1, 0, 3);
    A.scrivimatrice(1, 1, 4);

    cout << A.leggimatrice(0, 0) << endl;
    cout << A.leggimatrice(0, 1) << endl;
    cout << A.leggimatrice(1, 0) << endl;
    cout << A.leggimatrice(1, 1) << endl;


    return 0;
}

