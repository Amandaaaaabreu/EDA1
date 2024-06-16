#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N, topo;
} pilha;

int desempilha(pilha *p, int *y) {
    if (p->topo == 0) {
        // Pilha vazia, não é possível desempilhar
        return 0;
    }
    
    p->topo--; // indicar que um elemento está sendo removido
    *y = p->dados[p->topo]; // passando o elemento que está sendo removido pra varivel y. 
    
    return 1;
}

