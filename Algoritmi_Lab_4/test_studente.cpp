#include <iostream>
#include "studente.h"

int mainTestStudenteAlg4() {
    Studente s("Fisica", "ASD", "MAP", "Linguaggi", "Basi");
    s.setNome("Cica");
    s.setMatricola(1984195);
    s.setEsame(30, 0);
    s.setEsame(18, 1);
    s.setEsame(10, 2);
    s.setEsame(25, 3);

    s.printStudente();

    return 0;
}