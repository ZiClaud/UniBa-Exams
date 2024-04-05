"""
Per l’approssimazione di pi si consideri la seguente formula (Formula di Leibniz ):

Esercizio. Scrivere una funzione Python che abbia:
- INPUT: una tolleranza tol, un valore massimo di iterate consentite itmax.
- OUTPUT: Un intero n che rappresenta il numero minimo di termini da considerare nella formula
per raggiungere un’approssimazione di pi con errore assoluto non superiore a tol
"""


def leibniz(tol: float, itmax: int) -> int:
    return _leibniz(tol, itmax, 0, 0.0, 1)


def _leibniz(tol: float, itmax: int, itcurr: int, val: float, currmult: int) -> int:
    if itcurr >= itmax:
        print("Tolleranza non raggiunta")
        print("Pi: " + str(4 * val))
        return itcurr
    currval: float
    if itcurr % 2 == 0:
        currval = val + (1 / currmult)
    else:
        currval = val - (1 / currmult)

    if abs(4 * currval - 4 * val) < tol and val != 0:
        print("Tolleranza raggiunta")
        print("Pi: " + str(4 * currval))
        return itcurr

    return _leibniz(tol, itmax, itcurr + 1, currval, currmult + 2)


print(leibniz(1, 500))
print(leibniz(0.1, 500))
print(leibniz(0.01, 500))
print(leibniz(0.001, 500))

"""
Ripetere l’esercizio considerando, in luogo della (2), la seguente formula (di Viete):

In tal caso il parametro di output n rappresenta il numero minimo di fattori da considerare nella
seconda formula per ottenere un’approssimazione di ⇡ con errore assoluto minore di tol.
"""

# TODO