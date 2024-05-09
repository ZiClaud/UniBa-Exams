import numpy as np

"""
Ex 1
Scrivere una funzione Python che ha in input una matrice A generica e restituisce, in output, le ridotte a scalini di A.
"""


def riduci_a_scalini(A: np.array) -> np.array:
    for j in range(len(A)):
        A = _sottrai(A, j)
        # A[j][i] = i

    A = _order(A)

    return A


def _sottrai(A: np.array, j_curr: int) -> np.array:
    curr_row: np.array = A[j_curr]
    j: int = 0

    for row in A:
        i: int = 0
        den: float = 0
        for val in row:
            if j_curr >= j:
                break
            if curr_row[i] == 0:
                i += 1
                continue
            elif den == 0:
                den = - val / curr_row[i]

            if den != 0:
                val = val + curr_row[i] * den

            row[i] = val
            i += 1
        j += 1

    return A


def _order(A: np.array) -> np.array:
    len_row: int = len(A[0])
    zero_row: np.array = []

    zero_row_i: int = -1

    for i in range(len_row):
        zero_row.append(0)

    for i in range(len(A)):
        if np.array_equal(A[i], zero_row):
            zero_row_i = i
            break

    if zero_row_i == -1:
        # No changes needed, there's no row of zeros
        return A

    i: int = zero_row_i + 1
    while i < len(A):
        if not np.array_equal(A[i], zero_row):
            A[zero_row_i] = A[i]
            A[i] = zero_row
            A = _order(A)
        i += 1

    return A


"""
Ex 2
Scrivere una funzione Python che ha in input una matrice generica A e, in output, il rango di A.
Questa funzione drovrà far uso della funzione al punto precedente.
"""


def get_rango(A: np.array) -> int:
    A = riduci_a_scalini(A)

    i: int = 0
    len_row: int = len(A[0])
    zero_row: np.array = []

    for j in range(len_row):
        zero_row.append(0)

    for row in A:
        if np.array_equal(row, zero_row):
            break
        i += 1

    return i


if __name__ == '__main__':
    A = np.array([[1, 2, 3], [1, 3, 4]])
    A = np.array([[1, 2, 3], [1, 3, 4], [4, 3, 5]])

    A = np.array([[2., -1, 1], [4, -2, 2], [1, 3, 11], [1, -4, -10]])

    print(A)
    print(riduci_a_scalini(A)) # TODO: FIX -> Non funziona se e' gia' ridotta a scalini
    print(get_rango(A))
