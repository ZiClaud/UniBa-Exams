/*
Dato un albero binario di n nodi, contare i sottoalberi che hanno la somma dei nodi pari ad un intero k:

input:
      0
    /   \
 -6      2
   \    / \
   11  -4  7

k = 5

Output: 4
Ci sono 4 sottoalberi con somma 5.
 */


int somma(Albero T, int k) {
    if (!T.vuoto()) {
        int sum = 0;
        _somma(T, k, T.radice(), sum);
        return sum;
    }
    return 0;
}

int _somma(Albero T, int k, nodo n, int &s) {
    int sx = 0;
    int dx = 0;
    if (!T.sx_vuoto(n)) {
        sx = somma(T, k, T.sx(n));
    }
    if (!T.dx_vuoto(n)) {
        dx = somma(T, k, T.dx(n));
    }
    int sum = sx + dx + T.read(n);
    if (sum == k) {
        s++;
    }
}
