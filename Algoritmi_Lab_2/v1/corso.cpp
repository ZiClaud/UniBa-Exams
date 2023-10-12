#include "corso.h"
#include <iostream>
#include <cstring>
using namespace std;     // Removes std::

int setNomeCorso(corso* corso){
    cout << "Inserire nome corso:\n";
    char nome[30];
    cin >> nome;
    if (strlen(nome) >= 30) {
        cout << "Errore\n";
        return 1;
    }
    strcpy(corso->nome, nome);

    return 0;
}

int setNumStudenti(corso* corso, int n) {
    if (n > 300) {
        cout << "Errore\n";
        return 1;
    }
    corso->numStudenti = n;

    return 0;
}

int addStudente(corso* corso, studente studente) {
    // Se matricola non sta gia' -> return 1...
    setNumStudenti(corso, getNumStudenti(corso) + 1);
    corso->studenti[getNumStudenti(corso) - 1] = studente;

    return 0;
}

char* getNomeCorso(corso* corso) {
	return (corso->nome);
}

studente* getStudenti(corso* corso) {
	return (corso->studenti);
}

int getNumStudenti(corso* corso) {
    return corso->numStudenti;
}
