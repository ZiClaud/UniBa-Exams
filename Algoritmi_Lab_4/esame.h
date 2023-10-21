#ifndef _ESAME_H
#define _ESAME_H

#include <string>

using namespace std;

class Esame {
public:
    Esame();

    Esame(string);

    Esame(string, int);

    string getEsame();

    void setEsame(string);

    int getVoto();

    void setVoto(int);

    bool isSostenuto();

private:
    string nome;
    bool sostenuto;
    int voto;
};

#endif // _ESAME_H
