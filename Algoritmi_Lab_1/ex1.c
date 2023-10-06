/*
Lab 1
Scrivere in C/C++ in un file array.c l'implementazione delle seguenti funzioni che operano su array di elementi di tipo integer.
greaterThan: ha in input un array A ed un intero k e restituisce il numero di elementi di A che sono maggiori di k;
member: ha in input un array A ed un intero k e restituisce true se k e' presente in A;
largest: ha in input un array A e restutuisce il valore del piu' grande elemento presente in A e la sua posizione;
remove: ha in input un array A ed un intero k e elimina la prima occorrenza di k in A facendo uno shift a sinistra di tutti gli elementi che seguono k e scrivendo zero alla fine dell'array;
ordering: ha in input un array A ed stabilisce se gli elementi in A sono in ordine crescente, descrescente o costante;
reverse: ha in input un array A e lo modifca invertendone gli elementi.
find: funzione ricorsiva che ha in input un array A di elementi ordinati e stabilisce l'appartenenza di un elemento k.
chain: ha in input un intero k ed alloca dinamicamente una catena circolare di k celle (valore, next) e restituisce il puntatore ad una delle celle allocate. Dato il puntatore restituito dalla funzione chain, implementare la funzione clear che dealloca tutte le celle della catena.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct largest_pos {
    int num;
    int pos;
};

struct chain_item {
    int valore;
    struct chain_item* next;
};

void printArray(int arr[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

int greaterThan(int arr[], int len, int k){
    int val = 0;
    for (int i = 0; i < len; i++){
        if (arr[i] > k) {
            val++;
        }
    }

    return val;
}

bool member(int arr[], int len, int k){
    for (int i = 0; i < len; i++){
        if (arr[i] == k) {
            return true;
        }
    }

    return false;
}

struct largest_pos largest(int arr[], int len){
    struct largest_pos val = {-1, -1};

    if (len > 0) {
        val.num = arr[0];
        val.pos = 0;
    }

    for (int i = 0; i < len; i++){
        if (arr[i] > val.num) {
            val.num = arr[i];
            val.pos = i;
        }
    }

    return val;
}

void remove_(int arr[], int len, int k) {
    for (int i = 0; i < len; i++){
        if (arr[i] == k) {
            for (int j = i; j < len; j++) {
                if (j == len - 1) {
                    arr[j] = 0;
                    break;
                }
                arr[j] = arr[j+1];
            }
            break;
        }
    }
    
    return;
}

bool ordering(int arr[], int len) {
    bool costante = true;
    bool crescente = true;
    bool decrescente = true;

    for (int i = 0; i < len - 1; i++) {
        // Costante
        if (arr[i] != arr[i+1]){
            costante = false;
        }

        // Crescente
        if (arr[i] < arr[i+1]){
            crescente = false;
        }

        // Decrescente
        if (arr[i] > arr[i+1]){
            decrescente = false;
        }
    }

    return costante || crescente || decrescente;
}

void reverse(int arr[], int len) {
    int val;
    for (int i = 0; i < len/2; i++){
        val = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = val;
    }
    
    return;
}


bool find(int arr[], int len, int k, int curr){
    if (curr == len) {
        return false;
    }
    if (arr[curr] == k){
        return true;
    }

    return find(arr, len, k, curr+1);
}

struct chain_item* chain2(struct chain_item *item, int k){
    struct chain_item* new_item = ((struct chain_item*) malloc(sizeof(struct chain_item) * 1));
    (*new_item).valore = k;
    (*new_item).next = item;
    
    printf("Creata chain item: %d\n", k);
    printf("Posizione next item: %d\n", (*new_item).next);
    printf("Posizione item: %d\n", new_item);

    if (k <= 0) {
        return new_item;
    }

    return chain2(new_item, k - 1);
}

struct chain_item* chain(int k) {
    struct chain_item *item = ((struct chain_item*) malloc(sizeof(struct chain_item) * 1));
    (*item).valore = k;
    (*item).next = item;
    
    if (k <= 0){
        return item;
    }

    (*item).next = chain2(item, k - 1);

    return item;
}

void printChain(struct chain_item item, int k) {
    struct chain_item curr = item;
    for (int i = 0; i < k; i++) {
        printf("item val: %d\n", curr.valore);
        printf("item next: %d\n", curr.next);
        curr = *(curr.next);
    }
}

void clear(struct chain_item* item) {
    printChain(*item, 10);
    struct chain_item* curr = item;
    struct chain_item* currNext = (*curr).next;
    curr = (*curr).next;
    while (curr != item) {
        printf("Free di %d\n", (*curr).valore);
        currNext = (*curr).next;
        free(curr);
        curr = currNext;
        currNext = (*curr).next;
    }
    printf("Free di %d\n", (*curr).valore);
    free(curr);
}

int main() {
    int arr[6] = {1, 3, 3, 5, 7, 8};
    
    printf("greaterThan: %d\n", greaterThan(arr, 5, 4));
    printf("greaterThan: %d\n", greaterThan(arr, 5, 5));

    printf("member: %d\n", member(arr, 5, 4));
    printf("member: %d\n", member(arr, 5, 5));

    struct largest_pos val = largest(arr, 5);
    printf("largest: pos:%d num:%d\n", val.pos, val.num);

    printArray(arr, 5);
    remove_(arr, 5, 3);
    printArray(arr, 5);

    printf("ordering: %d\n", ordering(arr, 5));

    printArray(arr, 5);
    reverse(arr, 5);
    printArray(arr, 5);

    printf("find: %d\n", find(arr, 5, 4, 0));
    printf("find: %d\n", find(arr, 5, 3, 0));

    clear(chain(5));

    return 0;
}