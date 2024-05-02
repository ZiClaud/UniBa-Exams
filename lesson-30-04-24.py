import numpy as np

"""
Ex 1
Scrivere una funzione Python che ha in input una matrice A generica e restituisce, in output, le ridotte a scalini di A.
"""


def riduci_a_scalini(A: np.array) -> np.array:
    for j in range(len(A)):
        A = sottrai(A, j)
        # A[j][i] = i

    return A


def sottrai(A: np.array, j_curr: int) -> np.array:
    curr_row: np.array = A[j_curr]
    j: int = 0

    for row in A:
        i: int = 0
        den: float = 0
        for val in row:
            if j_curr >= j:
                break
            if curr_row[i] == 0:  # or np.array_equal(curr_row, row)
                i += 1
                continue
            elif den == 0:
                den = - val / curr_row[i]
                print("Den: ", den)
                print("-", val, "/", curr_row[i])

            if den != 0:
                print("val = ", val, "+", curr_row[i], "*", den)
                val = val + curr_row[i] * den
                print(val)

            row[i] = val
            i += 1
        j += 1

    return A


"""
Ex 2
Scrivere una funzione Python che ha in input una matrice generica A e, in output, il rango di A.
Questa funzione drovrà far uso della funzione al punto precedente.
"""


def get_rango(A: np.array) -> int:
    # TODO
    pass


if __name__ == '__main__':
    A = np.array([[1, 2, 3], [1, 3, 4]])

    # print(sottrai(np.array([[1, 2], [3, 4]]), 0))
    # print(sottrai(np.array([[1, 2], [3, 4]]), 1))

    print(A)
    print(riduci_a_scalini(A))
    print(get_rango(A))
