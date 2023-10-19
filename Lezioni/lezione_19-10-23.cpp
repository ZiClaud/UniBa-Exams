
void f() {
    int *p = new int;
    delete p;
}


void f2() {
    int *p;
    p = new int; // Punta a una nuova area
    p = new int; // Puntera' ad una nuova area
    delete p;
}


