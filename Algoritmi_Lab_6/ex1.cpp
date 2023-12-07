#include "coda.h"

void creaCodaSoloPositiviRic(Coda<int> c0, Coda<int> c1) {
    if (!c0.codaVuota()) {
        int curr = c0.leggiCoda();
        if (curr >= 0) {
            c1.inCoda(curr);
        }
        c0.fuoriCoda();
        creaCodaSoloPositiviRic(c0, c1);
        c0.inCoda(curr);
    }
}

Coda<int> creaCodaSoloPositivi(Coda<int> c) {
    Coda<int> ris(255);
    ris.creaCoda();
    creaCodaSoloPositiviRic(c, ris);
    return ris;
}
