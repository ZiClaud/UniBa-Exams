#include "studente.h"
#include <iostream>
#include <cstring>
//using namespace std;     // Removes std:: 


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

int setCognome(studente* studente){
    std::cout << "Inserire cognome:\n";
    char cognome[30];
    std::cin >> cognome;
    if (strlen(cognome) >= 30) {
        std::cout << "Errore\n";
        return 1;
    }
    strcpy(studente->cognome, cognome);
    return 0;
}

int setEta(studente* studente) {
    std::cout << "Inserire eta:\n";
    int eta;
    std::cin >> eta;
    if (eta < 12 || eta > 105) {
        std::cout << "Errore\n";
        return 1;
    }
	studente->eta = eta;
    return 0;
}

int setMatr(studente* studente) {
    std::cout << "Inserire matricola:\n";
    int matr;
    std::cin >> matr;
    if (matr < 255312 || matr > 499999) {
        std::cout << "Errore: matricola deve essere > 255312 e < 499999\n";
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

void printStudente(studente* studente){
    std::cout << "Nome: " << getNome(studente) << std::endl;
    std::cout << "Cognome: " << getCognome(studente) << std::endl;
    std::cout << "Eta: " << getEta(studente) << std::endl;
    std::cout << "Matricola: " << getMatr(studente) << std::endl;    
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    studente *studente1;
    setMatr(studente1);
    setNome(studente1);
    setCognome(studente1);
    setEta(studente1);

    printStudente(studente1);
    return 0;
}
