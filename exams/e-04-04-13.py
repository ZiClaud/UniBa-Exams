"""
Per l’approssimazione di pi si consideri la seguente formula (Formula di Leibniz ):

Esercizio. Scrivere una funzione Python che abbia:
- INPUT: una tolleranza tol, un valore massimo di iterate consentite itmax.
- OUTPUT: Un intero n che rappresenta il numero minimo di termini da considerare nella formula
per raggiungere un’approssimazione di pi con errore assoluto non superiore a tol
"""
from numpy import sqrt


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


# print(leibniz(1, 500))
# print(leibniz(0.1, 500))
# print(leibniz(0.01, 500))
# print(leibniz(0.001, 500))

"""
Ripetere l’esercizio considerando, in luogo della (2), la seguente formula (di Viete):

In tal caso il parametro di output n rappresenta il numero minimo di fattori da considerare nella
seconda formula per ottenere un’approssimazione di ⇡ con errore assoluto minore di tol.
"""


def _vietetest(it: int) -> float:
    val: float = 2 * (2 / sqrt(2))
    itcurr: int = 1

    while itcurr < it:
        i: int = 0
        den: float = 2

        while i < itcurr:
            den = 2 + sqrt(den)
            i += 1

        val = val * (2 / sqrt(den))
        itcurr += 1
        # print(val)

    # print(2.0)
    # print(2 * 2 / sqrt(2))
    # print(2 * 2 / sqrt(2) * 2 / sqrt(2 + sqrt(2)))
    # print(2 * 2 / sqrt(2) * 2 / sqrt(2 + sqrt(2)) * 2 / sqrt(2 + sqrt(2 + sqrt(2))))
    return val


#_vietetest(100)


def viete(tol: float, itmax: int) -> int:
    val: float = 2 * (2 / sqrt(2))
    oldval: float
    itcurr: int = 1

    while itcurr < itmax:
        oldval = val
        i: int = 0
        den: float = 2

        while i < itcurr:
            den = 2 + sqrt(den)
            i += 1

        val = val * (2 / sqrt(den))

        if abs(oldval - val) < tol:
            print("Tolleranza raggiunta")
            print("Pi: " + str(val))
            return itcurr

        itcurr += 1

    print("Tolleranza non raggiunta")
    print("Pi: " + str(val))
    return itcurr


print(viete(1, 500))
print(viete(0.1, 500))
print(viete(0.01, 500))
print(viete(0.001, 500))
print(viete(0.0001, 500))
print(viete(0.000000000001, 500))
