#include <iostream>
#include "esame.h"

Esame::Esame() {
    nome = "N/A";
    sostenuto = false;
    voto = -1;
}

Esame::Esame(string n) {
    nome = n;
    sostenuto = false;
    voto = -1;
}

Esame::Esame(string n, int v) {
    nome = n;
    voto = v;

    if (v >= 18) {
        sostenuto = true;
    } else {
        sostenuto = false;
    }
}

string Esame::getEsame() {
    return nome;
}

void Esame::setEsame(string n) {
    nome = n;
}

int Esame::getVoto() {
    return voto;
}

void Esame::setVoto(int v) {
    if (v >= 18) {
        sostenuto = true;
    } else {
        sostenuto = false;
    }
    voto = v;
}

bool Esame::isSostenuto() {
    return sostenuto;
}

void Esame::printEsame() {
    cout << getEsame() << ": " << getVoto() << endl;
}
