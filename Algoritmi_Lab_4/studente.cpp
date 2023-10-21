#include <iostream>
#include "studente.h"

Studente::Studente() : numEsami(5) {
    nome = "";
    matr = 0;
    esami.push_back(Esame());
    esami.push_back(Esame());
    esami.push_back(Esame());
    esami.push_back(Esame());
    esami.push_back(Esame());
}

Studente::Studente(string e1, string e2, string e3, string e4, string e5) : numEsami(5) {
    nome = "";
    matr = 0;
    esami.push_back(Esame(e1));
    esami.push_back(Esame(e2));
    esami.push_back(Esame(e3));
    esami.push_back(Esame(e4));
    esami.push_back(Esame(e5));
}

void Studente::setMatricola(int m) {
    matr = m;
}

void Studente::setNome(string n) {
    nome = n;
}

int Studente::getMatricola() {
    return matr;
}

string Studente::getNome() {
    return nome;
}

int Studente::getNumEsami() {
    return numEsami;
}

void Studente::setEsame(int voto, int i) {
    esami.at(i).setVoto(voto);
}

int Studente::getVotoEsame(int i) {
    return esami.at(i).getVoto();
}

string Studente::getNomeEsame(int i) {
    return esami.at(i).getEsame();
}

bool Studente::getSostenuto(int i) {
    return esami.at(i).isSostenuto();
}

int Studente::getMedia() {
    int somma_voti = 0;
    int sostenuti = 0;
    for (int i = 0; i < numEsami; ++i) {
        if (esami.at(i).isSostenuto()) {
            sostenuti++;
            somma_voti += getVotoEsame(i);
        }
    }
    return somma_voti / sostenuti;
}

void Studente::printStudente() {
    cout << "Studente: " << getNome() << endl;
    cout << "Matricola: " << getMatricola() << endl;
    cout << "Esami" << endl;
    for (int i = 0; i < numEsami; ++i) {
        if (esami.at(i).isSostenuto()) {
            esami.at(i).printEsame();
        }
    }
}
