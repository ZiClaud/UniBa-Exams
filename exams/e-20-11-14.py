"""
Esercizio. Scrivere una funzione Python che abbia in input un vettore x che individua una frazione
continua secondo la notazione (??) e che restituisca in output il valore della frazione continua calcolato
mediante l’espressione (??).
"""

from typing import List


def mediana_frazione(vec_x: List[int]):
    if len(vec_x) == 0:
        raise ValueError("No number found")
    elif len(vec_x) == 1:
        return vec_x[0]
    if (vec_x[0] <= 0):
        raise ValueError("Negative number found")
    return vec_x[0] + 1 / _mediana_frazione(vec_x, 1)


def _mediana_frazione(vec_x: List[int], curr: int):
    if (vec_x[curr] <= 0):
        raise ValueError("Negative number found")
    if curr + 1 == len(vec_x):
        return vec_x[curr]
    return vec_x[curr] + 1 / _mediana_frazione(vec_x, curr + 1)


print(mediana_frazione([3]))
print(mediana_frazione([3, 4, 12, 4]))

try:
    print(mediana_frazione([]))
except ValueError:
    print("Value Error")

try:
    print(mediana_frazione([3, 4, -12, 4]))
except ValueError:
    print("Value Error")
