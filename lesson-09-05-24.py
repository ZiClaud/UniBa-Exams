import numpy as np

"""
Ex 1
Scrivere una funzione python che abbia:
Input:
    x array dei nodi (x0, ..., xn)
    y array di ordine (y0, ..., yn
Output:
    yy array che contiene le valutazioni del polinomio che interpola i dati x, y, nei punti dell'array xx
In altri termini, indiceto con pn(x) il polinomio interpolente (pn(xi) = yi)
    yy(i) = pn(xx(i))
"""

# TODO

"""
Ex 2
Utilizzare la funzione al punto precedente all'interno di una nuova funzione che abbia:
Input:
    funzione f
    a, b, estremi dell'intervallo
    n: numero di nodi equidistanti dell'intervallo [a, b]
Output:
    grafico che rappresenti, nell'intervallo [a, b],
    - il grafico della funzione f,
    - i punti (xi, yi), i=0, ..., n
    - il grafico del polinomio pn(x)
"""

# TODO

"""
Ex 3
Eseguire la funzione al punto 2) sui seguenti esempi, e mostrare cosa succede al crescere di n.
    a) f(x) = e^-x * sin(2x)      x appartiene a [0, pi]
    b) f(x) = 1/(1+x^2)           x appartiene a [-5, 5]      (funzione di Runge)
"""

# TODO

if __name__ == '__main__':
    A = np.array([[1, 2, 3], [1, 3, 4]])
    A = np.array([[1, 2, 3], [1, 3, 4], [4, 3, 5]])

    A = np.array([[2., -1, 1], [4, -2, 2], [1, 3, 11], [1, -4, -10]])

    print(A)

# TODO: 4 - Slide 6 'interpolazione'
