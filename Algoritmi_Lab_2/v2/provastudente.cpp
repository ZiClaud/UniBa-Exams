#include <iostream>
#include "studente.h"

using namespace std;

// g++ -o provastudente provastudente.cpp studente.cpp

int mainStudenteAlg2v2() {
    cout << "Inizio\n";

    char n[30] = "Gianni";
    char c[30] = "Morandi";
    Studente studente1(255313, n, c, 32);
    studente1.printStudente();

    studente1.setNome();
    studente1.setCognome();
    studente1.setEta();
    studente1.setMatr();

    studente1.printStudente();

    return 0;
}
