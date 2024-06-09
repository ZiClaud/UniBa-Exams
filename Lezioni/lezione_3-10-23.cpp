#include <iostream>

std::cout << "Hello world!";

/*
namespace std {
  //...
}
*/


// " :: "     -> Operatore (Scope Resolution Operator)
// " cout "   -> Parola per indicare lo stream di output standard (lo schermo)
// " << "     -> Operatore di ridirezione dell'output, può essere concatenato

std::cout << "Hello world!" << "\n";
std::cout << "Hello world!" << std::endl;


// Specifica sintattica:
int fatt(int n);  // Forward declaration

int bin(int n, int k) {
    return fatt(n);     // ... ;
}


// Cosa facevamo in C
struct complex0 {
    double r;
    double i;
};

// Cosa facremo in C++
class complex1 {
private:
    double r;
    double i;
public:
    complex1(int real, int imaginary);

    double getReal() {
        return r;
    }

    complex1 sum(complex1);
    // double operator+(complex1&); // -> Modifica l'operatore " + "
};

complex1 c1; // Oggetto c1 (default)

complex1 c2(2, 3);

c2.getReal; // Il punto significa 'applica' .-.

complex1 c3 = c2.sum(c1);

// Rappresentiamolo come array
class complex2 {
private:
    double values[2];
public:
    complex2(int real, int imaginary);

    double getReal() {
        return values[0];
    }

    complex2 sum(complex2);
    // double operator+(complex2&);
};


// If we use operator+(complex&) -> We'll be able to do:
c3 = c2 + c1;



