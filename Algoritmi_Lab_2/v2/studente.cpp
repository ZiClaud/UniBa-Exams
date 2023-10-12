#include "studente.h"
#include <iostream>
#include <cstring>
using namespace std;

Studente::Studente(int matricolaStud, char nomeStud[30], char cognomeStud[30], int etaStud) {
    matricola = matricolaStud;
    strcpy(nome, nomeStud);
    strcpy(cognome, cognomeStud);
    eta = etaStud;
}

int Studente::setNome(){
    std::cout << "Inserire nome:\n";
    char nomeS[30];
    std::cin >> nomeS;
    if (strlen(nomeS) >= 30) {
    std::cout << "Errore\n";
    return 1;
    }
    strcpy(nome, nomeS);
    return 0;
}

int Studente::setCognome(){
    std::cout << "Inserire cognome:\n";
    char cognomeS[30];
    std::cin >> cognomeS;
    if (strlen(cognomeS) >= 30) {
    std::cout << "Errore\n";
    return 1;
    }
    strcpy(cognome, cognomeS);
    return 0;
}

int Studente::setEta() {
    std::cout << "Inserire eta:\n";
    int etaS;
    std::cin >> etaS;
    if (etaS < 12 || etaS > 105) {
    std::cout << "Errore\n";
    return 1;
    }
    eta = etaS;
    return 0;
}

int Studente::setMatr() {
    std::cout << "Inserire matricola:\n";
    int matr;
    std::cin >> matr;
    if (matr < 255312 || matr > 499999) {
    std::cout << "Errore: matricola deve essere > 255312 e < 499999\n";
    return 1;
    }
    matricola = matr;
    return 0;
}

char* Studente::getNome() {
    return nome;
}

char* Studente::getCognome() {
    return cognome;
}

int Studente::getEta() {
    return eta;
}

int Studente::getMatr() {
    return matricola;
}


void Studente::printStudente() {
    cout << "Nome: " << nome << endl;
    cout << "Cognome: " << cognome << endl;
    cout << "Eta: " << eta << endl;
    cout << "Matricola: " << matricola << endl;
}
