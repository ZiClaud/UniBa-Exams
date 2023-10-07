#include "studente.h"
#include <iostream>

int main() {
    std::cout << "Inizio\n";

    studente *studente1;
    setMatr(studente1);
    setNome(studente1);
    setCognome(studente1);
    setEta(studente1);

    //printStudente(studente1);
    return 0;
}
