#include <vector>
#include <stack>
#include <stdexcept>
#include "coda.h"

using namespace std;

/// Part1
void creaCodaSoloPositiviRic(Coda<int> c0, Coda<int> c1) {
    if (!c0.codaVuota()) {
        int curr = c0.leggiCoda();
        if (curr >= 0) {
            c1.inCoda(curr);
        }
        c0.fuoriCoda();
        creaCodaSoloPositiviRic(c0, c1);
        c0.inCoda(curr);
    }
}

Coda<int> creaCodaSoloPositivi(Coda<int> c) {
    Coda<int> ris(255);
    ris.creaCoda();
    creaCodaSoloPositiviRic(c, ris);
    return ris;
}


/// Part2
class Object {

};

class MultipleStack {
    vector<stack<Object>> stacks = vector<stack<Object>>();
    unsigned int len;
public:
    MultipleStack(unsigned int length) {
        len = length;
        for (int i = 0; i < len; ++i) {
            stacks.push_back(stack<Object>());
        }
    }

    void Push(Object &o, unsigned int stack) {
        if (stack >= len) {
            throw out_of_range("Overflow");
        }
        stacks[stack].push(o);
    }

    Object &Pop(unsigned int stack) {
        if (stack >= len) {
            throw out_of_range("Overflow");
        }

        Object &poppedObject = stacks[stack].top();
        stacks[stack].pop();
        return poppedObject;
    }
};
