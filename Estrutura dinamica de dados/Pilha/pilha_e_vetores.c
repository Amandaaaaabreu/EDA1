#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v; // Vetor que contem os elementos da pilha
    int N; // Tamanho de v
    int topo; // Indicador do topo
} pilha;

void empilha(pilha *p, int x) {
    if (p->topo == p->N) {
        // Pilha está cheia, dobrar o tamanho do vetor
        p->N *= 2;
        p->v = realloc(p->v, p->N * sizeof(int));
    }
    p->v[p->topo++] = x;
}

int desempilha(pilha *p, int *y) {
    if (p->topo == 0) {
        // Pilha está vazia
        return 0;
    }
    *y = p->v[--p->topo]; // atribuindo o elemento do topo da pilha para y 
    return 1;
}