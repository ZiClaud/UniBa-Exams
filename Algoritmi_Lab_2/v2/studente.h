// student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Studente {
private:
    int matricola;
	char nome[30];
    char cognome[30];
    int eta;

public:
    Studente(int matricolaS, char nomeS[], char cognomeS[30], int etaS);

    char* getNome();
    char* getCognome();
    int getEta();
    int getMatr();

    int setNome();
    int setCognome();
    int setEta();
    int setMatr();

    void printStudente();
};

#endif /* STUDENT_H */
