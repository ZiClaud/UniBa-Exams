import numpy as np

"""
Ex 1
Scrivere una funzione Python che ha in input una matrice A generica e restituisce, in output, le ridotte a scalini di A.
"""


def riduci_a_scalini(A: np.array) -> np.array:
    # TODO
    pass


"""
Ex 2
Scrivere una funzione Python che ha in input una matrice generica A e, in output, il rango di A.
Questa funzione drovrà far uso della funzione al punto precedente.
"""


def get_rango(A: np.array) -> int:
    # TODO
    pass


if __name__ == '__main__':
    A = np.array([[1, 2, 3], [4, 5, 6]])
    print(A)
    print(riduci_a_scalini(A))
    print(get_rango(A))
