/*
// TODO: Get text

class scontrino {
public:
    // aggiungere un prodotto allo scontrino
    void aggiungi(prodotto v);

    // rimuovere ...
    void rimuovi(prodotto v);

    double totale();

    prodotto costo();

    void stampa();

private:
    list <prodotto> S;
};
 */

using namespace std;

class scontrino {
public:

    class prodotto {
        string nome;
        double prezzo;
    };

    // aggiungere un prodotto allo scontrino
    void aggiungi(prodotto v);

    // rimuovere ...
    void rimuovi(prodotto v);

    double totale();

    prodotto costo();

    void stampa();

private:
    list <prodotto> S;
};