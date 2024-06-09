
/// Coda con Priorita'
/// Si crea con alberi, sono alberi parzialmente ordianti

/// *A e' un Array

void sort(int *A, int k) {
    CodaP<int> C;

    for (int i = 0; i < k; ++i) {
        C.inserisci(A[i]);
    }
    int j = 0;
    while (!C.vuota()) {
        A[j] = C.min;
        C.riumuovi_min();
        j++;
    }
}

/// Come faccio ad ordinare A senza usare una coda di supporto?

/*
 * Heap sort: Algoritmo di ordinamento che usa le code con priorita'
 */

template<class T>
void heapsort(T *a, int n) {
    for (int i = 0; i < n; ++i) {
        // TODO
    }
    for (int i = 0; i < n; ++i) {
        // TODO
    }
}
