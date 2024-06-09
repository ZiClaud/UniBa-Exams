/*
Dato un albero binario con nodi in R, inserire in una lista la media dei valori dei ??? per ogni livello.
In particolare l'elemento in posizione i della lista contiene la media di tutti i nodi dell'array posti sul
livello i.

Esempio: dato il seguenti albero binario

        0.3
       /  \
     2.1  3.4
    /  \  /  \

    // TODO: Finish text

 */

vector<double> media(Bintree<double> T) {
    vector<double> V;
    if (!T.empty()) {
        _media(T, T.root(), V, 1);  // 1 = livello del tree (io avrei messo 0)
    }
    return V;
}

void _media(Bintree<double> T, Bintree<double>::node n, vector<double> V, int depth) {
    if (V.size() < depth) {
        V.push_back(0);
    }
    V[depth] += T.read(n);
    if (!T.sx_empty()) {
        _media(T, T.sx, V, depth + 1);
    }
    if (!T.dx_empty()) {
        _media(T, T.dx, V, depth + 1);
    }
}
