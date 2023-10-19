#ifndef MATRIX_H
#define MATRIX_H

typedef double tipoelem;

// template <class T>
class Matrice {
public:
    int getRows();
    int getColomns();
    Matrice(int, int); /* costruttore */
    ~Matrice(); /* distruttore */
    tipoelem leggimatrice(int, int); // Al posto di scrivere "T" scrivo "tipoelem" -> In futuro sara' T
    void scrivimatrice(int, int, tipoelem);
    void prodottoScalare(double);
    Matrice trasposta();
    Matrice prodotto(Matrice M);
private:
    int righe;
    int colonne;
    tipoelem **elementi;
};

// con "T":
// matrice<int> A;
// matrice<double> B;

#endif /* MATRIX_H */
