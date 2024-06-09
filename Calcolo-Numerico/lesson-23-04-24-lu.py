import numpy as np


# list -> Matrix
def lu(A: list) -> [list, list]:
    # Fattorizzazione LU di una matrice
    m = len(A)
    n = len(A[0])
    if (m != n):
        print("Matrice non quadrata")
        return

    L = np.eye(n)  # Matrice identica (in matlab e np)

    k = 0
    while k < n - 1:
        i = k + 1
        while i < n:
            if A[k][k] == 0:
                print("Errore, divisione per zero")
                return

            mik = -A[i][k] / A[k][k]

            j = k + 1
            while j < n:
                A[i][j] = A[i][j] + mik * A[k][j]  # + o - ?
                j += 1
            L[i][k] = -mik
            i += 1
        k += 1

    U = np.triu(A)  # Matlab and np function

    return L, U


print(lu([[2, 1, 0, -1], [-2, -2, 1, -1], [4, 2, -1, -1], [0, 2, -3, 2]]))
