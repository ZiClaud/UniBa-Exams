#ifndef _CORSO
#define _CORSO

#include "studente.h"

struct tipocorso{
	char nome[30];
    studente studenti[300];
    int numStudenti;
};

typedef struct tipocorso corso;

int setNomeCorso(corso*);
int setNumStudenti(corso*, int);
int addStudente(corso*, studente);
int removeStudente(corso*, studente);

char* getNomeCorso(corso*);
studente* getStudenti(corso*);
int getNumStudenti(corso*);

#endif /* _CORSO */