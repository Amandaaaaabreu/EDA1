#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void em_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    no *pilha[100];
    int topo = -1;
    no *atual = raiz;

    while (1) {
        while (atual != NULL) {
            pilha[++topo] = atual;
            atual = atual->esq;
        }

        if (topo >= 0) {
            atual = pilha[topo--];
            printf("%d ", atual->dado);
            atual = atual->dir;
        } else {
            break;
        }
    }
}

