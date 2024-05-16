import numpy as np

"""
1) Scrivere una funzione python che abbia in input un vettore x e restituisca in output la matrice V di Vandermonde
"""


def vandermonde_matrix(x: np.array) -> np.array:
    n: int = len(x)

    V: np.array = np.zeros((n, n))

    for i in range(n):
        for j in range(n):
            V[i][j] = pow(x[i], j)

    return V


"""
2) Scrivere una funzione python che abbia un input due valori x e y delle stesse lunghezze e resituisca, in output, 
i coefficienti del polinomio interpolante in un vettore a
"""


def lagrange_interpolation(x: np.array, y: np.array) -> np.array:
    if len(x) != len(y):
        raise ValueError("x and y have different lengths")

    a: np.array = np.zeros(len(x))
    V: np.array = vandermonde_matrix(x)

    # TODO: Result should be: a = np.linalg.solve(V, y)

    return a


if __name__ == '__main__':
    x: np.array = np.array([1, 2, 3])
    y: np.array = np.array([2, 3, 5])

    print(vandermonde_matrix(x))
    print(lagrange_interpolation(x, y))
