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
    var: float

    for i in range(len(x)):
        var = 1
        for j in range(len(x)):
            if i != j:
                var *= (x - x[j]) / (x[i] - x[j])
            pass

    # TODO: Result should be: a = np.linalg.solve(V, y)
    # TODO: 3 - Slide 6 'interpolazione'
    a = np.linalg.solve(V, y)

    return a


def _lagrange_interpolation(x: np.array, y: np.array, k: int) -> float:  # Lk
    # TODO: Fix
    # TODO: Remove 'y'
    if len(x) != len(y):
        raise ValueError("x and y have different lengths")
    if len(x) < k:
        raise ValueError("x and y have less than k elements")

    ris: float = 1
    n: int = len(x)

    for i in range(n):
        if i != k:
            ris *= (- x[i]) / (x[k] - x[i])

    return ris * y[k]


def interpolate_polynomial(x, y):
    if len(x) != len(y):
        raise ValueError("Input vectors x and y must have the same length")

    n = len(x)
    coeffs = np.zeros(n)

    # Build the Lagrange basis polynomials and sum them to get the interpolating polynomial
    for i in range(n):
        L = np.ones(1)
        for j in range(n):
            if i != j:
                L = np.convolve(L, [1, -x[j]]) / (x[i] - x[j])
        coeffs = coeffs + y[i] * L

    return coeffs


if __name__ == '__main__':
    x: np.array = np.array([1., 2., 3.])
    y: np.array = np.array([2., 3., 5.])

    print("Vandermonde:\n", vandermonde_matrix(x))
    print("Lagrange:\n", lagrange_interpolation(x, y))

    x: np.array = np.array([3., -1.])
    y: np.array = np.array([3., -1.])

    print("Lagrange 0:\n", _lagrange_interpolation(x, y, 0))
    print("Lagrange 1:\n", _lagrange_interpolation(x, y, 1))
    # print("Lagrange 2:\n", _lagrange_interpolation(x, y, 2))

    x: np.array = np.array([2., -1.])
    y: np.array = np.array([2., -1.])

    print("Lagrange:\n", lagrange_interpolation(x, y))

    coeffs = interpolate_polynomial(x, y)
    print("Coefficients of the interpolating polynomial:", coeffs)

    # TODO: Test np.linalg.cond() for big n (around 10)
    # print(np.linalg.cond())
