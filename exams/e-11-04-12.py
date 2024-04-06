"""
La congettura di Collaz afferma che qualsiasi sia il punto iniziale x0, l’algoritmo raggiunge sempre il
valore 1 dopo un numero finito di passi, ovvero:

Esercizio. Si scriva una funzione Python che abbia in input un numero intero positivo x0 e
restituisca in output:
- il piu' piccolo intero n tale che xn = 1;
- un vettore x che contenga l’intera sequenza di valori x0, x1,...,xn.
"""


def collaz(x: int, seq: list[int] = [], n: int = 0):
    seq.append(x)
    if x == 1:
        return n, seq

    if x % 2 == 0:
        return collaz(int(x / 2), seq, n + 1)
    else:
        return collaz(3 * x + 1, seq, n + 1)


print(collaz(1, []))
print(collaz(2, []))
print(collaz(3, []))
print(collaz(4, []))
print(collaz(5, []))
print(collaz(9, []))
print(collaz(10, []))
