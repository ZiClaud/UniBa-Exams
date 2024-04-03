"""
Esercizio. Scrivere una funzione Python che abbia in input un vettore x che individua una frazione
continua secondo la notazione (??) e che restituisca in output il valore della frazione continua calcolato
mediante l’espressione (??).
"""

from typing import List


def mediana_frazione(vec_x: List[int]):
    return vec_x[0] + 1 / _mediana_frazione(vec_x, 1)


def _mediana_frazione(vec_x: List[int], curr: int):
    if curr + 1 == len(vec_x):
        return vec_x[curr]
    return vec_x[curr] + 1 / _mediana_frazione(vec_x, curr + 1)


print(mediana_frazione([3, 4, 12, 4]))
