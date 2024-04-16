"""
Calcola il determinante di una matrice (quadrata)
Mediante la regola di Laplace applicata alla prima riga
"""


def laplace(A: list) -> int:
    detA: int = 0

    m = len(A)
    n = len(A[0])
    if m != n:
        print("Error, matrice non quadrata")
        return

    if n == 1:
        detA = 1
    else:
        for j in range(n):
            # v1 - works in matlab
            # A1j = A
            # A1j[1, :] = []
            # A1j[:, j] = []

            # v2 - works in matlab
            # A1j = A[2:n, [1:j-1, j+1:n]]

            # vmine - TODO
            A1j = A[]


            detA = detA + (-1) ** (j + 1) * A[0][j] * laplace(A1j)

    return detA


print(laplace([[1, 2], [3, 4]]))
