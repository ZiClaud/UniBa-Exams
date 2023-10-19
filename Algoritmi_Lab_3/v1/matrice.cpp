#include "matrice.h"

Matrice::Matrice(int r, int c) {
    righe = r;
    colonne = c;

    elementi = new tipoelem *[righe];

    for (int i = 0; i < righe; i++) {
        elementi[i] = new tipoelem[colonne];
    }

}

// Distruttore
Matrice::~Matrice() {
    for (int i = 0; i < righe; i++) {
        delete[] elementi[i];
    }
    delete[] elementi;
}

tipoelem Matrice::leggimatrice(int r, int c) {
    return elementi[r][c];
}

void Matrice::scrivimatrice(int r, int c, tipoelem elem) {
    elementi[r][c] = elem;
}

//Matrice A;
// A.elementi[2][3];
