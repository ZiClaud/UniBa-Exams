import numpy as np

"""
Ex
Scrivere una funzione Python norma(A, s) con:
A = matrice generica
s = 1, inf
Che restituisce una la norma 1 o infinito della matrice A
"""


def norma(A: np.array, s) -> float:
    if s == "inf":
        return norma_inf(A)
    elif s == 1:
        return norma_uno(A)

    return -1


def norma_inf(A: np.array) -> float:
    curr: float = 0
    ris: float = 0
    for i in range(len(A)):
        for val in A[i]:
            curr += abs(val)
        if curr > ris:
            ris = curr
        curr = 0

    return ris


def norma_uno(A: np.array) -> float:
    curr: float = 0
    ris: float = 0
    for i in range(len(A)):
        for val in A:
            curr += abs(val[i])
        if curr > ris:
            ris = curr
        curr = 0

    return ris


if __name__ == '__main__':
    A = np.array([[1, -2, 0], [-1, 1, -2]])
    print(A)
    print(norma(A, 1))  # max {2, 3, 2} = 3
    print(norma(A, "inf"))  # max {3, 4} = 4
