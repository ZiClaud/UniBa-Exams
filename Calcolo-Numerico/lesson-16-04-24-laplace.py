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
        return -1

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

            # vmine
            A1j = remove_first(A)

            detA = detA + (-1) ** (j + 1) * A[0][j] * laplace(A1j)

    return detA


# Removes first line and first column of matrix
def remove_first(A: list) -> list:
    ris: list = A[1:]

    for i in range(len(ris)):
        ris[i] = ris[i][1:]

    return ris


print(remove_first([[1, 2], [3, 4]]))
print(remove_first([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))

print(laplace([[1, 2], [3, 4]]))
print(laplace([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
print(laplace([[0, 0, 0], [4, 5, 6], [7, 8, 9]]))
