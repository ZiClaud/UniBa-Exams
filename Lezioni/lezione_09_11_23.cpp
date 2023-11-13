// Pile

/*
/// Realizzazione con Array

template<class T>
class Pila {
public:
     ~Pila(){
        //TODO: Check if ok
        delete elementi;
     }

    Pila() {
        elementi = new T[10];
        testa = 0;
        dim = 10;
    }

    Pila(int k) {
        elementi = new T[k];
        testa = 0;
        dim = k;
    }

    bool pilavuota() {
        return (testa == 0);
    }

    T leggipila() {
        if (!pilavuota()) {
            return elementi[testa - 1];
        }
    }

    void inpila(T e) {
        if (testa < dim) {
            elementi[testa] = e;
            testa++;
        }
    }

    void fuoripila() {
        if (!pilavuota()) {
            testa--;
        }
    }

private:
    T *elementi;
    int dim;
    int testa;
};
*/


/// Realizzazione con puntatori
template<class T>
class Cella {
    friend class Pila;

private:
    T valore;
    Cella *next;
};


template<class T>
class Pila {
public:
    ~Pila(){
        //TODO
    }

    Pila() {
        testa = nullptr;
    }

    bool pilavuota() {
        return (testa == nullptr);
    }

    T leggipila() {
        if (testa != nullptr) {
            return (testa->valore);
        }
    }

    void inpila(T e) {
        Cella *tmp = new cella;
        tmp->next = testa;
        testa = tmp;
    }

    void fuoripila() {
        cella *tmp = testa;
        testa = testa->next;
        delete tmp;
    }

private:
    Cella *testa;
};

int main() {
    Pila P;
    Pila T(100);

    return 0;
};
