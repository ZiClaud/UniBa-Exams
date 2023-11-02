#include "studente.h"
#include "corso.h"
#include <iostream>

using namespace std;     // Removes std::

// When there wasn't corso.cpp ->
// g++ -o provastudente provastudente.cpp studente.cpp

// Now that we have corso.cpp too ->
// g++ -o provastudente provastudente.cpp studente.cpp corso.cpp

void printStudente(studente *studente) {
    cout << "Nome: " << getNome(studente) << endl;
    cout << "Cognome: " << getCognome(studente) << endl;
    cout << "Eta: " << getEta(studente) << endl;
    cout << "Matricola: " << getMatr(studente) << endl;
}

void printCorso(corso *corso) {
    studente *studenti = getStudenti(corso);
    cout << "Nome corso: " << getNomeCorso(corso) << endl;
    for (int i = 0; i < getNumStudenti(corso); i++) {
        cout << "Studente " << i + 1 << ": " << studenti[i].matricola << endl;
    }
}

int mainStudenteAlg2v1() {
    cout << "Inizio\n";

    studente studente1;
    setNome(&studente1);
    setCognome(&studente1);
    setEta(&studente1);
    setMatr(&studente1);

    printStudente(&studente1);

    studente studente2;
    setNome(&studente2);
    setCognome(&studente2);
    setEta(&studente2);
    setMatr(&studente2);

    corso corso1;
    setNumStudenti(&corso1, 0);
    setNomeCorso(&corso1);
    addStudente(&corso1, studente1);
    addStudente(&corso1, studente2);

    printCorso(&corso1);

    return 0;
}
