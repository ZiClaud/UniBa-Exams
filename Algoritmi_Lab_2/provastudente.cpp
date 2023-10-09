#include "studente.h"
#include <iostream>

// g++ -o provastudente provastudente.cpp studente.cpp

int main() {
    std::cout << "Inizio\n";

    studente studente1;
    setNome(&studente1);
    setCognome(&studente1);
    setEta(&studente1);
    setMatr(&studente1);

    //printStudente(&studente1);
    return 0;
}
