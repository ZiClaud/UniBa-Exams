//
// Created by ziclaud on 15/01/24.
//

#ifndef ALGORITMI_LAB_QUEUEV1_H
#define ALGORITMI_LAB_QUEUEV1_H

using namespace std;

template <class T>
class QueueV1 {
public:
    QueueV1();

    bool isEmpty();

    T read();

    void remove();

    void insert();
};

/*
- creacoda: () → coda
– codavuota: (coda) → boolean
– leggicoda: (coda) → tipoelem
– fuoricoda: (coda) → coda
– incoda: (tipoelem, coda) → coda
 */

#endif //ALGORITMI_LAB_QUEUEV1_H
