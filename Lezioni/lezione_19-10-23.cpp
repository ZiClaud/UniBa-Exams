
void f1() {
    int *p = new int;
    delete p;
}


void f2() {
    int *p;
    p = new int; // Punta a una nuova area
    p = new int; // Puntera' ad una nuova area
    delete p;
}



// Funzioni templatelezione_19-10-23
template <typename T1, typename T2>
T max(T1 x, T2 y);


// Classi template
template <class T>
class A {
    void f(T); // Generico
    void f(int); // Specializzazione -> Se usi un int usa questo codice
};
