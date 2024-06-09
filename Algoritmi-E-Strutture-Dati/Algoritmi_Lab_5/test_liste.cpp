#include <iostream>
#include "list_operations.h"

int main() {

    list<int> l = {1, 2, 3, 2, 1};
//    l.push_back(3);
//    l.push_back(4);
//    l.push_back(5);

    cout << l.size() << endl;

    cout << lunghezza(l) << endl;

    inverti(l);

    cout << palindoma(l) << endl;

    return 0;
}
