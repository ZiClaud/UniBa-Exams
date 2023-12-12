/// ALBERI N-ARI

void visita(Albero T) {
    if (!T.alberovuoto()) {
        visita(T, T.radice);
    }
}

void visita(Albero T, Nodo n) { // ?
    // PREVISITA o DFS
    while (!T.ultimofratello() ?) {
        // INVISTA ?
        visita(T, n);
        n = T.succfratello(n);
    }
    visita(T, n);
    // POSTVISTA?
    // TODO
}


void BFS(Albero T) {
    Coda C;
    C.incoda(T.radice());
    while (!C.vuota()) {
        // ...
    }
}

int maxprof(Albero T) {
    int max = 0;
    if (!T.alberovuoto()) {
        maxprof(T, T.radice, 1, max);
    }
    return max;
}

void maxprof(Albero T, Nodo n, int prof, int &max) {
    if (prof > max) {
        max = prof;
    }
    if (!T.foglia(n)) {
        Nodo m = T.primofiglio(n);
        while (!T.ultimofratello(m)) {
            maxprof(T, m, prof + 1);
            m = T.succfratello(m);
        }
        maxprof(T, m, prof + 1);
    }
}


/// Rimuovi sottoalbero
void removesubtree(Node n) {
    if (!foglia(n)) {
        Node q = primofiglio(n);
        while (!ultimofiglio(q)) {
            removesubtree(q);
        }
        removesubtree(q);
    }
    delete n;
}









