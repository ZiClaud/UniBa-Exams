#include "studente.h"
#include <iostream>
#include <cstring>
// using namespace std;     // Removes std:: 


/* funzioni per l'inserimento dei valori degli elementi della struttura */
int setNome(studente* studente){
    std::cout << "Inserire nome:\n";
    char nome[30];
    std::cin >> nome;
    if (strlen(nome) >= 30) {
        std::cout << "Errore\n";
        return 1;
    }
    strcpy(studente->nome, nome);
    return 0;
}

int setMatr(studente* studente) {
    std::cout << "Inserire matricola:\n";
    int matr;
    std::cin >> matr;
    if (matr < 255312 || matr > 499999) {
        std::cout << "Errore\n";
        return 1;
    }
	studente->matricola = matr;
    return 0;
}

/* funzioni per ottenere i valori degli elementi della struttura */
char* getNome(studente* studente) {
	return (studente->nome);
}

char* getCognome(studente* studente) {
	return (studente->cognome);
}

int getEta(studente* studente) {
	return (studente->eta);
}

int getMatr(studente* studente) {
    return (studente->matricola);
}

//...
