#ifndef _STUDENTE_H
#define _STUDENTE_H

#include "esame.h"
#include <vector>

class Studente {
private:
    string nome;
    int matr;
    vector<Esame> esami;
    const int numEsami;
public:
    Studente();

    Studente(string, string, string, string, string);

    void setMatricola(int);

    void setNome(string);

    int getMatricola();

    string getNome();

    int getNumEsami();

    void setEsame(int voto, int i);

    int getVotoEsame(int i);

    string getNomeEsame(int i);

    bool getSostenuto(int i);

    int getMedia();

    void printStudente();
};

#endif // _STUDENTE_H
