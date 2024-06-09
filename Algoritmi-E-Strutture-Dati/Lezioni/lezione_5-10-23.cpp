#include <iostream>
#include <vector>

class list {
private:
    // requisito astrazione...
    int values[10];
    int n_elems;
public:
    // requisito protezione...
    // metodi == operatori
    bool isEmpty() {
        return (n_elems == 0);
    }
};


class list2 {
    // head --> [_,_] --> [_,_] --> ...

    // se head è vuoto:
    // head = nullptr;
private:
    node *head; // Ci sarà class 'node' con 2 variabili: value e next
public:
    bool isEmpty() {
        //return (n_elems == 0);
        return (head == nullptr);
    }
};


class list3 {
private:
    int *values;
    int n_elems;
public:
    bool isEmpty() {
        return (n_elems == 0);
    }
};

list3 l3 = list3(10);


template<class T> // E' una generics adesso - Classe template - Classe astratta
class list4 {
private:
    T *values; // T -> Significa int, double, ...
    int n_elems;
public:
    bool isEmpty() {
        return (n_elems == 0);
    }
};

list4<int> a;
list4<double> b;


int i[10];

i[3]; // Posso scrivere/leggere l'elemento in quella posizione

a = i[3] = 0;

vector<int> v1; // #include <vector> (ved cplusplus.com -> reference -> containers)



// Perche' esiste #include <array> ?
int main1() { // Individua l'errore
    int a[5], b[5];
    a[7] = 0;
}

int main2() { // Non individua l'errore
    int a[5], b[5];

    double f[10];
    int q;

    a[7] = 0;
}

// Soprattutto con la scanf -> Heckers possono entrare e fare danni



