/*
#ifdef GRAFOMAT_H
#define GRAFOMAT_H

[] -> [] [] [] []
[]
[]
[]
*/

/// Grafi (ved realizzazione)

class NodoG {
public:
    NodoG(int id) {
        nodoId = id;
    }

    NodoG() {}

    int getId() { return nodoId; }

    void setId(int id) { nodoId = id; };
private:
    int nodoId;
};

template<class T, class E>
class InfoNodo {
public:
    E etichetta;
    std::List<int> archiUscenti;
}

template<class E, class P>
void GrafoMat<E,P>::insArco(Nodo n1, Nodo n2, P peso) {
    matrice[n1.getId]; // ...
    /// ...
}


int test() {
    GrafoList<string, double> G(10);

    NodoG n1, n2, n3, n4, n5, n6;

    G.insNodo(n1);
    G.scriviEtichetta(n1, "1");
    G.insNodo(n2);
    G.scriviEtichetta(n1, "2");
    /// ...


}

