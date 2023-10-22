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

tipoelem getPordotto(Matrice &A, Matrice &B, int r, int c){
    tipoelem ris = 0;

    // TODO: Fix
    for (int i = 0; i < A.getRows(); ++i) {
        for (int j = 0; j < B.getColomns(); ++j) {
            ris += A.leggimatrice(i, r) + B.leggimatrice(j, c);
        }
    }
    
    return ris;
}

/// A * M
Matrice Matrice::prodotto(Matrice M) {
    if (righe != M.getColomns()) {
        throw runtime_error("Errore, prodotto non possibile");
    }

    Matrice ris = Matrice(righe, M.colonne);

    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < M.colonne; ++j) {
            ris.scrivimatrice(i, j, getPordotto(*this, M, i, j));
        }
    }

    return ris;
}

// Getters (not asked)
int Matrice::getRows() {
    return righe;
}

int Matrice::getColomns() {
    return colonne;
}

// Print (not asked)
void Matrice::printMatrix(){
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getColomns(); ++j) {
            cout << leggimatrice(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}