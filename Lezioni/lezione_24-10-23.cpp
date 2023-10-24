
// Passo base: Lista vuota
A = [];

// Lista ricorsiva:
A = [X][L];  // Dove L e' una lista, X un elemento



// Slide: Liste pg 10
while (!finelista(p)) {
    // ...
    p = succlista();
}

// Slide: Liste pg. 12 - finelista
listavuota = finelista(primolista());   // Se la lista e' vuota -> E' falso

// Slide: Liste pg. 13 - inslista
[a1, a2, a3] ->
pos(2) [a1, a2, a, a3] o [a1, a, a2, a3]?

[a1, a, a2, a3]


// Slide: Liste pg. 16 - Pseudocodice
duplicati(L)    // Posso applicarla solo se la lista non e' vuota
    if (!listavuota(L))
        p = primolista(L)
        while (!finelista(p, L))
            q = succlisa(p, L)
            while (!finelista(q, L)
                if (leggilista(p, L) == leggilista(q, L)
                    canclista(q, L)
                q = succlista(q, L)
            p = succlista(p, L)


// Ora in C++
template <class T> // Funziona solo quando T e' un tipo primitivo (== funziona solo per i primitivi)
void duplicati(Lista<T> L) {
    Listaz<T>::posizione p,q;
    if (!L.listavuota()) {
        p = L.primolista();
        while (!L.finelista(p)) {
            q = L.succlisa(p)
            while (!L.finelista(q) {
                if (L.leggilista(p) == L.leggilista(q) {
                    L.canclista(q);
                }
                q = L.succlista(q);
            }
            p = L.succlista(p);
        }
    }
};

// Slide pg 18.
class List {
public:
    empty();
private:
    int elementi[10];   // Nella classe template -> *elementi
    int n;
};

[v1, pnext]; // Realizzazione statica (uso array) con cursori (pnext)


// Slide pg 36

class Cella {
    friend Lista;   // La classe Lista puo' accedere agli elementi di Cella
private:
    int v;
    cella *next;
};

class Lista {
private:
    Cella *L;   // Punta alla prima cella
};
