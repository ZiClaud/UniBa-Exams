// Code
void stampapila(Pila P) {
    if (!pilavuota(P)) {
        e = leggipila(P);
        stampa(e);
        fuoripila(P);
        stampapila(P);
        inpila(P, e);
    }
}

/*
// Wrong
void stampapila(Pila P) {
    Pila P1;
    while (!pilavuota(P)) {
        stampa(leggipila(P));
        impila(P1,leggipila(P));
        fuoripila(P);
    }
    while (!pilavuota(P1)) {
        impila(P, leggipila(P1));
        fuoripila(P1);
    }
}
*/

// 3 casi:

// 1
template<class T>
class cella {
public:
    cella();

private:
    T e;
    cella *next;
};

// 2
template<class T>
class coda {
public:
    coda();

private:
    cella *testa;
    cella *coda;
};

// TODO: Continuare
// 3
template<class T>
class coda {
public:
    coda();

private:
    class cella {
    public:
        cella();

    private:
        T e;
        cella *next;
    };
};





