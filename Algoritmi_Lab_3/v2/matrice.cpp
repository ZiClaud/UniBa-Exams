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
    if (elementi) {
        for (int i = 0; i < righe; i++) {
            delete[] elementi[i];
        }
        delete[] elementi;
    }
}

tipoelem Matrice::leggimatrice(int r, int c) {
    return elementi[r][c];
}

void Matrice::scrivimatrice(int r, int c, tipoelem elem) {
    elementi[r][c] = elem;
}

void Matrice::prodottoScalare(double scalare) {
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            scrivimatrice(i, j, leggimatrice(i, j) * scalare);
        }
    }
}

Matrice Matrice::trasposta() {
    Matrice matrice(colonne, righe);
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            matrice.scrivimatrice(j, i, leggimatrice(i, j));
        }
    }
    return matrice;
}

// TODO: Matrice prodotto

// Getters (not asked)
int Matrice::getRows() {
    return righe;
}

int Matrice::getColomns() {
    return colonne;
}
