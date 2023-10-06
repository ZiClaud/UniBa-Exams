#ifndef _STUDENTE
#define _STUDENTE

struct tipostudente{
	int matricola;
	char nome[30];
    char cognome[30];
    int eta;
	//...
};

typedef struct tipostudente studente;

/* funzioni per l'inserimento dei valori degli elementi della struttura */
int setNome(studente *);
int setCognome(studente *);
//...
/* funzioni per ottenere i valori degli elementi della struttura */
char * getNome(studente *);
///...

#endif /* _STUDENTE */