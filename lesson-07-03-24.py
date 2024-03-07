from numpy import *


# from scipy import *   # per avere operazioni scientifiche in piu'

def bisezioni(f, a, b, tol, itmax):
    """
    Metodo delle successive bisezioni

    Parametri di input:
    f: funzione di cui ricercare uno zero
    [a,b]: intervallo di lavoro
    tol: Precisione richiesta/Tolleranza
    itmax: Numero massimo di iteraze consentite (buona regola)

    Parametri di output:
    alpha: zero di f

    Help bisezioni -> dice roba
    """

    fa = f(a)
    fb = f(b)
    if fa * fb > 0:
        print('La funzione non cambia segno agli estremi dell''intervallo')
        return

    it = 0

    while b - a > tol and it < itmax:
        it = it + 1
        c = (a + b) / 2
        fc = f(c)
        if fc == 0:
            return c
        elif fa * fc < 0:
            b = c
            fb = fc
        else:
            a = c
            fa = fc

    if b - a > tol:
        print('precisione non raggiunta')

    return c


def f1(x):
    return x - cos(x)


def f2(x):
    return x - exp(-x)
