#include <iostream>
#include "esame.h"

int mainTestEsameAlg4() {
    Esame e1 = Esame();
    Esame e2 = Esame("Fisica");
    Esame e3 = Esame("ASD", 30);

    cout << e1.getEsame() << endl;
    cout << e1.getVoto() << endl;
    cout << e1.isSostenuto() << endl << endl;

    cout << e2.getEsame() << endl;
    cout << e2.getVoto() << endl;
    cout << e2.isSostenuto() << endl << endl;

    cout << e3.getEsame() << endl;
    cout << e3.getVoto() << endl;
    cout << e3.isSostenuto() << endl << endl;

    return 0;
}