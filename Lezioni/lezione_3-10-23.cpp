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

int bin (int n, int k){
  return fatt(n)/...;
}


// Cosa facevamo in C
struct complex {
  double r;
  double i;
};

// Cosa facremo in C++
class complex {
private:
  double r;
  double i;
public:
  complex(real, real);
  double getReal() {
    return r1;
  }
  complex sum(complex);
  // double operator+(complex&); // -> Modifica l'operatore " + "
};

complex c1; // Oggetto c1 (default)

complex c2(2, 3);

c2.getReal; // Il punto significa 'applica' .-.

complex c3 = c2.sum(c1);

// Rappresentiamolo come array
class complex2 {
private:
  double values[2];
public:
  complex(real, real);
  double getReal() {
    return values[0];
  }
  complex sum(complex);
  // double operator+(complex&);
};


// If we use operator+(complex&) -> We'll be able to do:
c3 = c2 + c1;



